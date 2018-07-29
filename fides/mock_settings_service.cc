// Copyright 2015 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <string>

#include "fides/identifier_utils.h"
#include "fides/mock_settings_service.h"

namespace fides {

MockSettingsService::MockSettingsService() {}

MockSettingsService::~MockSettingsService() {}

BlobRef MockSettingsService::GetValue(const Key& key) const {
  auto entry = prefix_value_map_.find(key);
  return entry != prefix_value_map_.end() ? BlobRef(&entry->second) : BlobRef();
}

const std::set<Key> MockSettingsService::GetKeys(const Key& prefix) const {
  std::set<Key> result;
  for (const auto& entry : utils::GetRange(prefix, prefix_value_map_))
    result.insert(entry.first);
  return result;
}

void MockSettingsService::AddSettingsObserver(SettingsObserver* observer) {
  absl::WriterMutexLock writer_lock(&observers_mutex_);
  observers_.insert(observer);
}

void MockSettingsService::RemoveSettingsObserver(SettingsObserver* observer) {
  absl::WriterMutexLock writer_lock(&observers_mutex_);
  observers_.erase(observer);
}

void MockSettingsService::SetValue(const Key& key,
                                   const std::string& value) {
  prefix_value_map_[key] = value;
  std::set<Key> changed_keys;
  changed_keys.insert(key);
  NotifyObservers(changed_keys);
}

void MockSettingsService::NotifyObservers(const std::set<Key>& keys) {
  absl::ReaderMutexLock reader_lock(&observers_mutex_);
  for (auto &observer : observers_) {
    observer->OnSettingsChanged(keys);
  }
}

}  // namespace fides
