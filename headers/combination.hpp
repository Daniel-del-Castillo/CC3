#pragma once

#include <array>

template<unsigned SIZE1, unsigned SIZE2>
std::array<unsigned, SIZE1 + SIZE2> combination(
    const std::array<unsigned, SIZE1>& array1,
    const std::array<unsigned, SIZE2>& array2) noexcept {
    std::array<unsigned, SIZE1 + SIZE2> result;
    for (auto i = 0; i < SIZE1; i++) {
        result[i] = array1[i];
    }
    for (auto i = 0; i < SIZE2; i++) {
        result[i + SIZE1] = array2[i];
    }
    return result;
}

