workspace(name = "fides")

http_archive(
      name = "com_github_nelhage_boost",
      sha256 = "5c88fc077f6b8111e997fec5146e5f9940ae9a2016eb9949447fcb4b482bcdb3",
      strip_prefix = "rules_boost-7289bb1d8f938fdf98078297768c122ee9e11c9e",
      urls = [
          "https://mirror.bazel.build/github.com/nelhage/rules_boost/archive/7289bb1d8f938fdf98078297768c122ee9e11c9e.tar.gz",
          "https://github.com/nelhage/rules_boost/archive/7289bb1d8f938fdf98078297768c122ee9e11c9e.tar.gz",
      ],
)

# This can't be inside cartographer_repositories() because of:
# https://github.com/bazelbuild/bazel/issues/1550
load("@com_github_nelhage_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

http_archive(
      name = "com_github_gflags_gflags",
      sha256 = "6e16c8bc91b1310a44f3965e616383dbda48f83e8c1eaa2370a215057b00cabe",
      strip_prefix = "gflags-77592648e3f3be87d6c7123eb81cbad75f9aef5a",
      urls = [
          "https://mirror.bazel.build/github.com/gflags/gflags/archive/77592648e3f3be87d6c7123eb81cbad75f9aef5a.tar.gz",
          "https://github.com/gflags/gflags/archive/77592648e3f3be87d6c7123eb81cbad75f9aef5a.tar.gz",
      ],
)

http_archive(
      name = "com_google_glog",
      sha256 = "dfc074b41a5b86fc5dda4f0e2e2d6cc5b21f798c9fcc8ed5fea9c8f7c4613be6",
      strip_prefix = "glog-dd2b93d761a19860190cb3fa92066c8031e912e3",
      urls = [
          "https://mirror.bazel.build/github.com/google/glog/archive/dd2b93d761a19860190cb3fa92066c8031e912e3.tar.gz",
          "https://github.com/google/glog/archive/dd2b93d761a19860190cb3fa92066c8031e912e3.tar.gz",
      ],
)

# Bazel toolchains
http_archive(
  name = "bazel_toolchains",
  urls = [
    "https://mirror.bazel.build/github.com/bazelbuild/bazel-toolchains/archive/287b64e0a211fb7c23b74695f8d5f5205b61f4eb.tar.gz",
    "https://github.com/bazelbuild/bazel-toolchains/archive/287b64e0a211fb7c23b74695f8d5f5205b61f4eb.tar.gz",
  ],
  strip_prefix = "bazel-toolchains-287b64e0a211fb7c23b74695f8d5f5205b61f4eb",
  sha256 = "aca8ac6afd7745027ee4a43032b51a725a61a75a30f02cc58681ee87e4dcdf4b",
)

# GoogleTest/GoogleMock framework. Used by most unit-tests.
http_archive(
     name = "com_google_googletest",
     urls = ["https://github.com/google/googletest/archive/b4d4438df9479675a632b2f11125e57133822ece.zip"],  # 2018-07-16
     strip_prefix = "googletest-b4d4438df9479675a632b2f11125e57133822ece",
     sha256 = "5aaa5d566517cae711e2a3505ea9a6438be1b37fcaae0ebcb96ccba9aa56f23a",
)

http_archive(
      name = "com_google_absl",
      sha256 = "387cf016ab1ab8530d1cea8975276ce8d8bff355133776129bdc400d05519eb6",
      strip_prefix = "abseil-cpp-44aa275286baf97fc13529aca547a88b180beb08",
      urls = ["https://github.com/abseil/abseil-cpp/archive/44aa275286baf97fc13529aca547a88b180beb08.tar.gz"],
)

http_archive(
    name = "com_github_google_benchmark",
    urls = ["https://github.com/google/benchmark/archive/16703ff83c1ae6d53e5155df3bb3ab0bc96083be.zip"],
    strip_prefix = "benchmark-16703ff83c1ae6d53e5155df3bb3ab0bc96083be",
    sha256 = "59f918c8ccd4d74b6ac43484467b500f1d64b40cc1010daa055375b322a43ba3",
)

http_archive(
    name = "boringssl",
    # on the chromium-stable-with-bazel branch
    url = "https://boringssl.googlesource.com/boringssl/+archive/dcd3e6e6ecddf059adb48fca45bc7346a108bdd9.tar.gz",
)
