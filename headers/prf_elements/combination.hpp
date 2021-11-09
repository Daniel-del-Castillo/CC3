#pragma once

#include <array>
#include <algorithm>

template<unsigned N, unsigned M>
using fn = std::function<std::array<unsigned, M>(std::array<unsigned, N>)>;

// This function represents the combination basic function.
// Formal definition:
// ℎ = 𝑓 𝑥 𝑔: 𝑁𝑛 → 𝑁𝑚+𝑘 
// Using:
// 𝑓: 𝑁𝑛 → 𝑁𝑚 
// 𝑔: 𝑁𝑛 → 𝑁𝑘 
// Defined as:
// ℎ: 𝑁𝑛 → 𝑁𝑚+𝑘 
// 𝑋 = (𝑥1,⋯,𝑥𝑛) ∈ 𝑁𝑛 → ℎ(𝑋)= (𝑓(𝑋),𝑔(𝑋))
template<unsigned N, unsigned M, unsigned K>
fn<N, M + K> combination(
    const fn<N, M>& f,
    const fn<N, K>& g
) {
    return [&]
        (const std::array<unsigned, N>& array)
        -> std::array<unsigned, M + K> {
        std::array<unsigned, M> array1 = f(array);
        std::array<unsigned, K> array2 = g(array);
        std::array<unsigned, M + K> result;
        std::copy(array1.begin(), array1.end(), result.begin());
        std::copy(array2.begin(), array2.end(), result.begin() + N);
        return result;
    };
}