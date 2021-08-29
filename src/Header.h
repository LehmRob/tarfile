// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//
#pragma once

#include <array>
#include <cstdint>
#include <string>

namespace tarfile {

constexpr std::size_t k_blockSize = 512;

// The header structure is taken from the gnu header file tar.h
struct Header {
    static Header construct(std::array<char, k_blockSize>);

    std::string str();

    // Basicheader complex
    std::array<char, 100> _name;
    std::array<char, 8> _mode;
    std::array<char, 8> _uid;
    std::array<char, 8> _gid;
    std::array<char, 12> _size;
    std::array<char, 12> _mtime;
    std::array<char, 8> _chksum;
    char _typeflag;
    std::array<char, 100> _linkname;
    std::array<char, 6> _magic;
    std::array<char, 2> _version;
    std::array<char, 32> _uname;
    std::array<char, 32> _gname;
    std::array<char, 8> _devmajor;
    std::array<char, 8> _devminor;
    std::array<char, 155> _prefix;
};

} // namespace tarfile
