// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//

#include "Header.h"

#include <array>
#include <cstdio>
#include <iostream>
#include <string>

namespace tarfile {

Header Header::construct(const char block[], size_t size = 512) {
    Header h;

    h.name_ = std::string(block, 100);
    h.mode_ = std::stoul(std::string(&block[100], 8), nullptr, 8);
    h.uid_ = std::stoi(std::string(&block[108], 8));
    h.gid_ = std::stoul(std::string(&block[116], 8));
    h.size_ = std::stoul(std::string(&block[124], 12));

    return h;
}

} // namespace tarfile
