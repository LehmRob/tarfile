#pragma once

// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//

#include <array>
#include <cstdint>
#include <string>

namespace tarfile {

enum class HeaderFileType : char {
    NormalFile = '0',
    HardLink = '1',
    SymbolicLink = '2',
    CharacterSpecial = '3',
    BlockSpecial = '4',
    Directory = '5',
    Fifo = '6',
};

// The header structure is taken from the gnu header file tar.h
class Header {
  public:
    Header() = default;
    static Header construct(const char[]);

    std::string name() { return name_; }
    std::uint64_t mode() { return mode_; }
    int uid() { return uid_; }
    int gid() { return gid_; }
    std::uint64_t size() { return size_; }
    std::uint64_t mtime() { return mtime_; }
    std::uint32_t checksum() { return chksum_; }
    HeaderFileType typeflag() { return typeflag_; }

  private:
    // Basicheader complex
    std::string name_;        // h[0] - 100
    std::uint32_t mode_ = 0;  // h[100] - 8
    int uid_;                 // h[108] - 8
    int gid_;                 // h[116] - 8
    std::uint64_t size_;      // h[124] - 12
    std::uint64_t mtime_;     // h[136] - 12
    std::uint32_t chksum_;    // h[148] - 8
    HeaderFileType typeflag_; // h[156] - 1
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
