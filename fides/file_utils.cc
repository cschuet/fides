// Copyright 2015 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "fides/file_utils.h"

#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "boost/filesystem.hpp"
#include "boost/filesystem/fstream.hpp"
#include "glog/logging.h"

namespace fides {

namespace utils {

namespace {

enum FileType {
  FILES = 1 << 0,
  DIRECTORIES = 1 << 1,
};

std::vector<std::string> ListEntries(const std::string& path, int file_type) {
  std::vector<std::string> entries;
  boost::filesystem::path p (path);
  boost::filesystem::directory_iterator end_itr;
  for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr)
  {
    if ((FILES & file_type) && is_regular_file(itr->path())) {
      entries.push_back(itr->path().filename().string());
    }
    else if ((DIRECTORIES & file_type) && is_directory(itr->path())) {
       entries.push_back(itr->path().filename().string());
    }
  }
  return entries;
}

}  // namespace

std::vector<std::string> ListFiles(const std::string& path) {
  return ListEntries(path, FILES);
}

std::vector<std::string> ListDirectories(const std::string& path) {
  return ListEntries(path, DIRECTORIES);
}

bool CreateDirectory(const std::string& path) {
  boost::filesystem::path boost_path(path);
  return boost::filesystem::create_directory(boost_path);
}

bool PathExists(const std::string& path) {
  boost::filesystem::path boost_path(path);
  return boost::filesystem::exists(boost_path);
}

bool DeleteFile(const std::string& path) {
  boost::filesystem::path boost_path(path);
  return boost::filesystem::remove(boost_path);
}

bool ReadFile(const std::string& path,
		std::vector<uint8_t>* contents,
	         size_t max_size) {
  boost::filesystem::ifstream ifs{path, std::ios::binary};

  // Determine filesize.
  ifs.seekg (0, ifs.end);
  unsigned int file_size = ifs.tellg();
  ifs.seekg (0, ifs.beg);

  if (file_size > max_size) {
    return false;
  }
  contents->resize(file_size);
  ifs.read((char*) contents->data(), file_size);
  return true;
}

bool WriteFileAtomically(const std::string& path,
                         const uint8_t* data,
	         size_t size) {
  boost::filesystem::ofstream ofs{path, std::ios::binary};
  ofs.write((char*) data, size);
  return true;
}

}  // namespace utils

}  // namespace fides
