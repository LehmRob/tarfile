// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <array>
#include <cstdio>

#include "../src/Header.h"

#include "hello.tar.h"

using Catch::Matchers::Contains;

TEST_CASE("Test if testframework works", "[HEADER]") {
    auto header = tarfile::Header::construct(hello_data);

    REQUIRE_THAT(header.name(), Contains("hello.txt"));
    REQUIRE(header.mode() == 0644);
    REQUIRE(header.uid() == 1750);
    REQUIRE(header.gid() == 1750);
    REQUIRE(header.size() == 15);
    REQUIRE(header.mtime() == 14106237313);
    REQUIRE(header.checksum() == 12560);
    REQUIRE(header.typeflag() == tarfile::HeaderFileType::NormalFile);
    REQUIRE(header.linkname()[0] == '\0');
    // REQUIRE(header.magic() == "ustar");
    REQUIRE_THAT(header.magic(), Contains("ustar"));
}
