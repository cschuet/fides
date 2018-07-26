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
  name = "key",
  hdrs = ["key.h"],
  srcs = ["key.cc"],
  deps = [
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

cc_library(
  name = "blob_ref",
  hdrs = ["blob_ref.h"],
  srcs = ["blob_ref.cc"],
  deps = [
    "@com_google_glog//:glog",
  ],
)

