#pragma once

#include <array>
#include <functional>

template<unsigned SIZE1, unsigned SIZE2>
using fn = std::function<std::array<unsigned, SIZE2>(std::array<unsigned, SIZE1>)>;

// This function represents the composition basic function.
template<unsigned SIZE1, unsigned SIZE2, unsigned SIZE3>
fn<SIZE1, SIZE3> composition(
    const fn<SIZE1, SIZE2>& function1,
    const fn<SIZE2, SIZE3>& function2) noexcept {
    return [&]
        (const std::array<unsigned, SIZE1>& array)
        -> std::array<unsigned, SIZE3> {
        return function2(function1(array));
    };
}
