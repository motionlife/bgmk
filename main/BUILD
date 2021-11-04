load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "hello_greet",
    srcs = ["hello_greet.cc"],
    hdrs = ["hello_greet.h"],
    deps = [
        "//proto:person_cc_proto",
    ]
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = [
        ":hello_greet",
        "//lib:hello_time",
        "@com_google_absl//absl/strings",
    ],
)

cc_test(
    name = "hello_test",
    srcs = ["hello_test.cc"],
    deps = [
        ":hello_greet",
        "//proto:person_cc_proto",
        "@com_google_googletest//:gtest_main",
    ],
)