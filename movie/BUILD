load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "api_key",
    hdrs = ["api_key.h"],
    visibility = [":__subpackages__"],
)

cc_binary(
    name = "runner",
    srcs = ["data_fetcher_runner.cc"],
    deps = [
        ":api_key",
        "//movie/data_fetcher:meta_data_processor",
        "//movie/data_fetcher:movie_db_repository",
        "//movie/data_fetcher:movie_db_data_factory",
    ],
)