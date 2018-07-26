// Copyright 2015 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <set>

#include "boost/filesystem.hpp"
#include "fides/blob_store.h"
#include "fides/file_utils.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

namespace fides {

namespace {

bool IsHandleValid(const BlobStore::Handle& handle) {
  return handle.IsValid();
}

void CheckBlobs(const std::set<std::vector<uint8_t>>& expected_blobs,
                const std::vector<BlobStore::Handle>& handles,
                const BlobStore& store) {
  std::set<std::vector<uint8_t>> read_blobs;
  for (auto& handle : handles)
    read_blobs.insert(store.Load(handle));
  EXPECT_EQ(expected_blobs, read_blobs);
}

}  // namespace

class BlobStoreTest : public ::testing::Test {
 public:
  BlobStoreTest() {}
  ~BlobStoreTest() override {}

  void SetUp() override {
	  path_ = boost::filesystem::temp_directory_path().string() + "/" + boost::filesystem::unique_path().string();
	  utils::CreateDirectory(path_);
  }

  void TearDown() override {
	  boost::filesystem::remove_all(path_);
  }

  std::string GetStoragePath() {
	  return path_;
  }

  std::string GetSourcePath(const std::string& source_id) {
    return GetStoragePath() + "/" + source_id;
  }

  const std::vector<uint8_t> CreateBlob(const std::string& data) {
    return std::vector<uint8_t>(data.begin(), data.end());
  }

 private:
  std::string path_;

  DISALLOW_COPY_AND_ASSIGN(BlobStoreTest);
};

TEST_F(BlobStoreTest, StoreListAndLoad) {
  const std::vector<uint8_t> blob(CreateBlob("DATA"));
  std::string source_id = "SOURCE1";
  BlobStore store(GetStoragePath());

  // Store.
  BlobStore::Handle h = store.Store(source_id, BlobRef(&blob));
  EXPECT_TRUE(h.IsValid());

  // List.
  std::vector<BlobStore::Handle> handles = store.List(source_id);
  EXPECT_EQ(1, handles.size());
  EXPECT_TRUE(std::all_of(handles.begin(), handles.end(), IsHandleValid));

  // Load.
  const std::vector<uint8_t> read_blob(store.Load(h));
  EXPECT_EQ(blob, read_blob);
}

TEST_F(BlobStoreTest, ListWithBogusFilename) {
  BlobStore store(GetStoragePath());

  const std::vector<uint8_t> blob0(CreateBlob("DATA0"));
  std::string source_id = "SOURCE1";

  // Set up some bogus files.
  utils::CreateDirectory(GetSourcePath(source_id));
  utils::WriteFileAtomically(GetSourcePath(source_id) + "/" + "blob_AAA",
                             blob0.data(), blob0.size());
  utils::WriteFileAtomically(GetSourcePath(source_id) + "/" + "blob_009",
                             blob0.data(), blob0.size());
  utils::WriteFileAtomically(GetSourcePath(source_id) + "/" + "blob_00001",
                             blob0.data(), blob0.size());

  // List.
  std::vector<BlobStore::Handle> handles = store.List(source_id);
  EXPECT_EQ(1, handles.size());
  EXPECT_TRUE(std::all_of(handles.begin(), handles.end(), IsHandleValid));
  std::set<std::vector<uint8_t>> expected_blobs = {blob0};
  CheckBlobs(expected_blobs, handles, store);

  // Store a good blob.
  const std::vector<uint8_t> blob1(CreateBlob("DATA1"));
  BlobStore::Handle h = store.Store(source_id, BlobRef(&blob1));
  EXPECT_TRUE(h.IsValid());

  // List again and check blob contents.
  handles = store.List(source_id);
  EXPECT_EQ(2, handles.size());
  EXPECT_TRUE(std::all_of(handles.begin(), handles.end(), IsHandleValid));
  expected_blobs = {blob0, blob1};
  CheckBlobs(expected_blobs, handles, store);

  // Store another good blob.
  std::vector<uint8_t> blob2(CreateBlob("DATA2"));
  BlobStore::Handle h2 = store.Store(source_id, BlobRef(&blob2));
  EXPECT_TRUE(h2.IsValid());

  // List again and check blob contents.
  handles = store.List(source_id);
  EXPECT_EQ(3, handles.size());
  EXPECT_TRUE(std::all_of(handles.begin(), handles.end(), IsHandleValid));
  expected_blobs = {blob0, blob1, blob2};
  CheckBlobs(expected_blobs, handles, store);
}

}  // namespace fides
