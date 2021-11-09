#pragma once

#include <array>
#include <functional>

template<unsigned NARGS, unsigned NRETURN>
using fn = std::function<std::array<unsigned, NRETURN>(std::array<unsigned, NARGS>)>;

// This function represents the composition basic function.
// Formal definition:
// ℎ=𝑓 ∘(𝑔1,...,𝑔𝑚): 𝑁𝑛 → 𝑁𝑘 
// Using:
// 𝑓: 𝑁𝑚 → 𝑁𝑘 
// and several functions 𝑔𝑖, 𝑖 =1,...,𝑚 
// 𝑔𝑖: 𝑁𝑛 → 𝑁 
// Defined as:
// ℎ: 𝑁𝑛 → 𝑁𝑘 
// 𝑋 = (𝑥1,⋯,𝑥𝑛) ∈ 𝑁𝑛  → ℎ(𝑋)= 𝑓(𝑔1(𝑋) ,...,𝑔𝑚(𝑋)) 
// 
// To guarantee a simpler implementation instead of several g
// functions you should use only one g function defined as following:
// g: 𝑁𝑛 → 𝑁𝑘 
// If you have multiple g functions you can use the combination operator
// to combine them
template<unsigned N, unsigned M, unsigned K>
fn<N, K> composition(
    const fn<M, K>& f,
    const fn<N, M>& g
) {
    return [&]
        (const std::array<unsigned, N>& array)
        -> std::array<unsigned, K> {
        return f(g(array));
    };
}
