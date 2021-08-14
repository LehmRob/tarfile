// Copyright (c) 2021 Robert Lehmann <lehmrob@posteo.net>
//
// SPDX-License-Identifier: MIT
//
#pragma once

#include <array>
#include <cstdlib>

namespace tarfile {

template <typename DType, typename SType>
bool memcpy(DType dest, SType src, size_t size, off_t offest = 0) {
    for (int i = offest; i < size; i++) {
        dest[i] = src[i];
    }

    return false;
}

} // namespace tarfile
