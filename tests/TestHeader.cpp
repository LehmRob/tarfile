// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <array>

#include "hello.tar.h"

TEST_CASE("Test if testframework works", "[HEADER]") { REQUIRE(1 == 1); }
