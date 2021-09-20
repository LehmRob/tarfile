// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//

#include "Header.h"

#include <cstdio>
#include <iostream>
#include <string>

namespace tarfile {

static HeaderFileType convert(char typeflag) {
    return static_cast<HeaderFileType>(typeflag);
}

Header Header::construct(const char block[]) {
    Header h;

    h.name_ = std::string(block, 100);
    h.mode_ = std::stoul(std::string(&block[100], 8), nullptr, 8);
    h.uid_ = std::stoi(std::string(&block[108], 8));
    h.gid_ = std::stoul(std::string(&block[116], 8));
    h.size_ = std::stoul(std::string(&block[124], 12));
    h.mtime_ = std::stoull(std::string(&block[136], 12));
    h.chksum_ = std::stoul(std::string(&block[148], 8));
    h.typeflag_ = convert(block[156]);
    h.linkname_ = std::string(&block[157], 100);
    h.magic_ = std::string(&block[257], 6);

    return h;
}

} // namespace tarfile
