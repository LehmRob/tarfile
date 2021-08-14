// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//
#pragma once

#include <array>
#include <cstdint>
#include <cstdlib>

#include "Header.hpp"

namespace tarfile {

class TarFile {
  public:
    TarFile(Header &header) : _header(header) {}

    static TarFile constructFromFile(const char *file);

  private:
    Header _header;
};

} // namespace tarfile
