cc_library(
  name = "test_helpers",
  hdrs = ["test_helpers.h"],
  srcs = ["test_helpers.cc"],
  deps = [
    ":key",
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "blob_store",
  hdrs = ["blob_store.h"],
  srcs = ["blob_store.cc"],
  deps = [
    ":blob_ref",
    ":key",
    ":file_utils",
    "@com_google_absl//absl/strings:str_format",
    "@com_google_glog//:glog",
    "//base:macros",
  ],
)

cc_test(
    name = "blob_store_unittest",
    size = "small",
    srcs = ["blob_store_unittest.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":blob_store",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
  name = "file_utils",
  hdrs = ["file_utils.h"],
  srcs = ["file_utils.cc"],
  deps = [
    "@com_google_glog//:glog",
    "@boost//:filesystem",
  ],
)

cc_library(
  name = "settings_service",
  hdrs = ["settings_service.h"],
  deps = [
    "//base:macros",
    ":blob_ref",
    ":key",
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "mock_settings_service",
  hdrs = ["mock_settings_service.h"],
  srcs = ["mock_settings_service.cc"],
  deps = [
    "//base:macros",
    ":identifier_utils",
    ":settings_service",
    "@com_google_absl//absl/synchronization",
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "settings_keys",
  hdrs = ["settings_keys.h"],
  srcs = ["settings_keys.cc"],
  deps = [
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "source",
  hdrs = ["source.h", "source_delegate.h"],
  srcs = ["source.cc", "source_delegate.cc"],
  deps = [
    "//base:macros",
    ":blob_ref",
    ":locked_settings",
    ":settings_keys",
    ":settings_service",
    "@com_google_glog//:glog",
    "@com_google_absl//absl/strings",
  ],
)

cc_test(
    name = "source_unittest",
    size = "small",
    srcs = ["source_unittest.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":identifier_utils",
        ":mock_settings_document",
        ":mock_settings_service",
        ":source",
        ":test_helpers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
  name = "key",
  hdrs = ["key.h"],
  srcs = ["key.cc"],
  deps = [
    "@com_google_glog//:glog",
  ],
)

cc_test(
    name = "key_unittest",
    size = "small",
    srcs = ["key_unittest.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":key",
        ":test_helpers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
  name = "identifier_utils",
  hdrs = ["identifier_utils.h"],
  deps = [
    ":key",
    "@com_google_glog//:glog",
  ],
)

cc_test(
    name = "identifier_utils_unittest",
    size = "small",
    srcs = ["identifier_utils_unittest.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":identifier_utils",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
  name = "locked_settings",
  hdrs = ["locked_settings.h"],
  srcs = ["locked_settings.cc"],
  deps = [
    "//base:macros",
    ":blob_ref",
    ":settings_document",
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "mock_settings_document",
  hdrs = ["mock_settings_document.h"],
  srcs = ["mock_settings_document.cc"],
  deps = [
    "//base:macros",
    ":blob_ref",
    ":identifier_utils",
    ":settings_document",
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "settings_blob_parser",
  hdrs = ["settings_blob_parser.h"],
  srcs = ["settings_blob_parser.cc"],
  deps = [
    "//base:macros",
    ":blob_ref",
    ":locked_settings",
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "mock_locked_settings",
  hdrs = ["mock_locked_settings.h"],
  srcs = ["mock_locked_settings.cc"],
  deps = [
    "//base:macros",
    ":blob_ref",
    ":locked_settings",
    ":mock_settings_document",
    ":settings_document",
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "version_stamp",
  hdrs = ["version_stamp.h"],
  srcs = ["version_stamp.cc"],
  deps = [
    "@com_google_glog//:glog",
  ],
)

cc_test(
    name = "version_stamp_unittest",
    size = "small",
    srcs = ["version_stamp_unittest.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":version_stamp",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
  name = "blob_ref",
  hdrs = ["blob_ref.h"],
  srcs = ["blob_ref.cc"],
  deps = [
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "settings_document",
  hdrs = ["settings_document.h"],
  srcs = ["settings_document.cc"],
  deps = [
    ":blob_ref",
    ":blob_store",
    ":key",
    ":version_stamp",
    "@com_google_glog//:glog",
  ],
)

cc_test(
    name = "settings_document_unittest",
    size = "small",
    srcs = ["settings_document_unittest.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":mock_settings_document",
        ":settings_document",
        ":test_helpers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
  name = "settings_document_manager",
  hdrs = ["settings_document_manager.h"],
  srcs = ["settings_document_manager.cc"],
  deps = [
    "//base:macros",
    ":blob_ref",
    ":blob_store",
    ":identifier_utils",
    ":settings_blob_parser",
    ":settings_map",
    ":settings_service",
    ":source",
    "@com_google_absl//absl/synchronization",
    "@com_google_glog//:glog",
  ],
)

cc_test(
    name = "settings_document_manager_unittest",
    size = "small",
    srcs = ["settings_document_manager_unittest.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":file_utils",
        ":mock_locked_settings",
        ":settings_document_manager",
        ":simple_settings_map",
        ":test_helpers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
  name = "settings_map",
  hdrs = ["settings_map.h"],
  deps = [
    "//base:macros",
    ":blob_ref",
    ":settings_document",
    "@com_google_glog//:glog",
  ],
)

cc_library(
  name = "simple_settings_map",
  hdrs = ["simple_settings_map.h"],
  srcs = ["simple_settings_map.cc"],
  deps = [
    "//base:macros",
    ":identifier_utils",
    ":settings_map",
    "@com_google_glog//:glog",
  ],
)

cc_test(
    name = "simple_settings_map_unittest",
    size = "small",
    srcs = ["simple_settings_map_unittest.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":mock_settings_document",
        ":simple_settings_map",
        ":test_helpers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
  name = "crypto",
  hdrs = ["crypto.h"],
  srcs = ["crypto_openssl.cc"],
  deps = [
    ":blob_ref",
    "@boringssl//:ssl",
    "@com_google_glog//:glog",
  ],
)