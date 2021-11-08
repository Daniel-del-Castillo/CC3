#pragma once

#include <array>
#include <algorithm>

template<unsigned SIZE1, unsigned SIZE2>
using fn = std::function<std::array<unsigned, SIZE2>(std::array<unsigned, SIZE1>)>;

// This function represents the combination basic function.
template<unsigned SIZE1, unsigned SIZE2, unsigned SIZE3>
fn<SIZE1, SIZE2 + SIZE3> combination(
    const fn<SIZE1, SIZE2>& function1,
    const fn<SIZE1, SIZE3>& function2
) noexcept {
    return [&]
        (const std::array<unsigned, SIZE1>& array)
        -> std::array<unsigned, SIZE2 + SIZE3> {
        std::array<unsigned, SIZE2> array1 = function1(array);
        std::array<unsigned, SIZE3> array2 = function2(array);
        std::array<unsigned, SIZE2 + SIZE3> result;
        std::copy(array1.begin(), array1.end(), result.begin());
        std::copy(array2.begin(), array2.end(), result.begin() + SIZE1);
        return result;
    };
}