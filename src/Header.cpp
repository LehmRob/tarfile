// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//

#include "Header.hpp"

#include <array>
#include <string>

#include "memcpy.hpp"

namespace tarfile {

Header Header::construct(std::array<char, k_blockSize> block) {
    Header h;

    memcpy(h._name, block, h._name.size());
    memcpy(h._gname, block, h._gname.size(), 100);

    return h;
}

std::string Header::str() { return ""; }

} // namespace tarfile
