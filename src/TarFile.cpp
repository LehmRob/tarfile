// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT

#include "TarFile.hpp"

#include <array>
#include <cstdint>
#include <cstdlib>
#include <cstring>

#include "memcpy.hpp"

namespace tarfile {

TarFile TarFile::constructFromFile(const char *filename) {
    std::array<char, 512> headerData = {'a', 'b', 'c'};

    auto h = Header::construct(headerData);

    return TarFile(h);
}

} // namespace tarfile
