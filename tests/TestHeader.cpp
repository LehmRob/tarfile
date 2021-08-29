// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <array>

#include "../src/Header.h"

#include "hello.tar.h"

using Catch::Matchers::Contains;

TEST_CASE("Test if testframework works", "[HEADER]") {
    auto header = tarfile::Header::construct(hello_data, 512);

    REQUIRE_THAT(header.name(), Contains("hello.txt"));
    REQUIRE(header.mode() == 0644);
    REQUIRE(header.uid() == 1750);
    REQUIRE(header.gid() == 1750);
    REQUIRE(header.size() == 15);
}
