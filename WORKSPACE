load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# RapidJson
http_archive(
    name = "rapidjson",
    urls = [
        "https://github.com/Tencent/rapidjson/archive/v1.1.0.tar.gz",
    ],
    sha256 = "bf7ced29704a1e696fbccf2a2b4ea068e7774fa37f6d7dd4039d0787f8bed98e",
    strip_prefix = "rapidjson-1.1.0",
    build_file = "//:third_party/rapidjson.BUILD",
)
# Zlib
http_archive(
    name = "zlib",
    sha256 = "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
    strip_prefix = "zlib-1.2.11",
    urls = [
            "https://zlib.net/zlib-1.2.11.tar.gz",
            "https://mirror.bazel.build/zlib.net/zlib-1.2.11.tar.gz",
        ],
    build_file = "//:third_party/zlib.BUILD",
)

# BoringSSL
http_archive(
    name = "boringssl",
    # Use github mirror instead of https://boringssl.googlesource.com/boringssl
    # to obtain a boringssl archive with consistent sha256
    sha256 = "f0f433106f98f6f50ed6bbc2169f7c42dd73d13d0f09d431082519b5649903a6",
    strip_prefix = "boringssl-56eb68f64215738552be452e311da12047934ab4",
    urls = [
        "https://github.com/google/boringssl/archive/56eb68f64215738552be452e311da12047934ab4.tar.gz",
    ],
)

# Curl on GitHub
http_archive(
    name = "com_github_curl_curl",
    urls = [
        "https://curl.haxx.se/download/curl-7.69.1.tar.gz",
    ],
    strip_prefix = "curl-7.69.1",
    sha256 = "01ae0c123dee45b01bbaef94c0bc00ed2aec89cb2ee0fd598e0d302a6b5e0a98",
    build_file = "//:third_party/curl.BUILD",
)

# abseil-cpp
http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/ddb842f583e560bbde497bc96cfebe25f9089e11.zip"],
  strip_prefix = "abseil-cpp-ddb842f583e560bbde497bc96cfebe25f9089e11",
)

# Google Test
http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/16f637fbf4ffc3f7a01fa4eceb7906634565242f.zip"],
  strip_prefix = "googletest-16f637fbf4ffc3f7a01fa4eceb7906634565242f",
)

# Protocol Buffer
http_archive(
    name = "rules_proto",
    sha256 = "66bfdf8782796239d3875d37e7de19b1d94301e8972b3cbd2446b332429b4df1",
    strip_prefix = "rules_proto-4.0.0",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
    ],
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()