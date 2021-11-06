#pragma once

#include <array>

template<int SIZE1, int SIZE2>
std::array<int, SIZE1 + SIZE2> combination(
    const std::array<int, SIZE1>& array1,
    const std::array<int, SIZE2>& array2) noexcept {
    std::array<int, SIZE1 + SIZE2> result;
    for (auto i = 0; i < SIZE1; i++) {
        result[i] = array1[i];
    }
    for (auto i = 0; i < SIZE2; i++) {
        result[i + SIZE1] = array2[i];
    }
    return result;
}