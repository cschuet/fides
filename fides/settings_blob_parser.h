// Copyright 2015 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FIDES_SETTINGS_BLOB_PARSER_H_
#define FIDES_SETTINGS_BLOB_PARSER_H_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "base/macros.h"

#include "fides/blob_ref.h"

namespace fides {

class LockedSettingsContainer;

// A settings blob parser is just a function that creates a SettingsBlob object
// from a serialized representation provided as a sequence of bytes. |format|
// identifies the file format to expect, which can be used to select the
// appropriate parsing logic.
using SettingsBlobParserFunction = std::function<std::unique_ptr<
    LockedSettingsContainer>(const std::string& format, BlobRef data)>;

// This is a helper that allows to construct a parser which will delegate to a
// set of subordinate parsers depending on format. Note that
// SettingsBlobParserRegistry is not copyable, but can be wrapped in std::ref()
// to turn it into a callable that can be used as a SettingsBlobParserFunction.
class SettingsBlobParserRegistry {
 public:
  SettingsBlobParserRegistry();

  // Register a parser for the specified format.
  void Register(const std::string& format,
                const SettingsBlobParserFunction& parser);

  // Run the parsers, return the SettingsBlob generated by the parser registered
  // to handle |format|. Returns nullptr if there is no parser for |format| or
  // the parser fails to parse |data|.
  std::unique_ptr<LockedSettingsContainer> operator()(const std::string& format,
                                                      BlobRef data) const;

 private:
  std::unordered_map<std::string, SettingsBlobParserFunction> parsers_;

  DISALLOW_COPY_AND_ASSIGN(SettingsBlobParserRegistry);
};

}  // namespace fides

#endif  // FIDES_SETTINGS_BLOB_PARSER_H_