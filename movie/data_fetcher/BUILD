load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "error_repository",
    hdrs = ["error_repository.h"],
)

cc_library(
    name = "file_error_repository",
    hdrs = ["file_error_repository.h"],
    srcs = ["file_error_repository.cc"],
    deps = [
        ":error_repository",
        ]
)

cc_library(
    name = "invalid_input_exception",
    hdrs = ["invalid_input_exception.h"],
)

cc_library(
    name = "movie_not_found_exception",
    hdrs = ["movie_not_found_exception.h"],
)

cc_library(
    name = "movie_data",
    hdrs = ["movie_data.h"],
    srcs = ["movie_data.cc"],
)

cc_library(
    name = "movie_meta_data_repository",
    hdrs = ["movie_meta_data_repository.h"],
    deps = [
        ":movie_data",
    ],
)

cc_library(
    name = "movie_data_factory",
    hdrs = ["movie_data_factory.h"],
    deps = [
        ":movie_data",
    ],
)

cc_library(
    name = "meta_data_processor",
    hdrs = ["meta_data_processor.h"],
    srcs = ["meta_data_processor.cc"],
    deps = [
        ":movie_meta_data_repository",
        ":movie_data",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "settable_movie_data",
    hdrs = ["settable_movie_data.h"],
    deps = [
        ":movie_data",
    ]
)

cc_library(
    name = "json_helper",
    hdrs = ["json_helper.h"],
    srcs = ["json_helper.cc"],
    deps = [
        "@rapidjson//:rapidjson",
        ":invalid_input_exception",
        ":movie_not_found_exception",
        ]
)

cc_library(
    name = "rest_api_client",
    hdrs = ["rest_api_client.h"],
    srcs = ["rest_api_client.cc"],
    deps = [
        "@com_github_curl_curl//:curl",
        ]
)

cc_library(
    name = "string_html_encoder",
    hdrs = ["string_html_encoder.h"],
)

cc_library(
    name = "movie_db_data_factory",
    hdrs = ["movie_db_data_factory.h"],
    srcs = ["movie_db_data_factory.cc"],
    deps = [
        ":movie_data_factory",
        ":settable_movie_data",
        "@rapidjson//:rapidjson",
        ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "movie_db_repository",
    hdrs = ["movie_db_repository.h"],
    srcs = ["movie_db_repository.cc"],
    deps = [
        ":movie_meta_data_repository",
        ":rest_api_client",
        ":movie_data_factory",
        ":json_helper",
        ":movie_not_found_exception",
        ":string_html_encoder",
        ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "json_helper_test",
    srcs = ["json_helper_test.cc"],
    deps = [
        ":json_helper",
        ":movie_not_found_exception",
        ":invalid_input_exception",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "meta_data_processor_test",
    srcs = ["meta_data_processor_test.cc"],
    deps = [
        ":meta_data_processor",
        ":movie_data",
        ":movie_db_repository",
        ":movie_db_data_factory",
        "//movie:api_key",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "string_html_encoder_test",
    srcs = ["string_html_encoder_test.cc"],
    deps = [
        ":string_html_encoder",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "movie_db_data_factory_test",
    srcs = ["movie_db_data_factory_test.cc"],
    deps = [
        ":movie_db_data_factory",
        "@com_google_googletest//:gtest_main",
    ],
)