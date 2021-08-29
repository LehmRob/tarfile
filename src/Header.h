// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//
#pragma once

#include <array>
#include <cstdint>
#include <string>

namespace tarfile {

// The header structure is taken from the gnu header file tar.h
struct Header {
    static Header construct(const char[], size_t);

    std::string name() { return name_; }
    uint64_t mode() { return mode_; }
    int uid() { return uid_; }
    int gid() { return gid_; }
    uint64_t size() { return size_; }

    // Basicheader complex
    std::string name_;       // h[0] - 100
    std::uint32_t mode_ = 0; // h[100] - 8
    int uid_;                // h[108] - 8
    int gid_;                // h[116] - 8
    std::uint64_t size_;     // h[124] - 12
    std::array<char, 12> mtime_;
    std::array<char, 8> chksum_;
    char typeflag_;
    std::array<char, 100> linkname_;
    // after here its get magic
    std::array<char, 6> magic_;
    std::array<char, 2> version_;
    std::array<char, 32> uname_;
    std::array<char, 32> gname_;
    std::array<char, 8> devmajor_;
    std::array<char, 8> devminor_;
    std::array<char, 155> prefix_;
};

} // namespace tarfile
