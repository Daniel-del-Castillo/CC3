#pragma once

#include <array>

// Zero basic function
// 𝑧: 𝑁 → 𝑁
// 𝑥 ∈ 𝑁 → 𝑧(𝑥) = 0 ∈ 𝑁
std::array<unsigned, 1> zero(const std::array<unsigned, 1>& array)  {
    return {0};
}

// Successor basic function
// 𝑧: 𝑁 → 𝑁
// 𝑥 ∈ 𝑁 → 𝑧(𝑥) = 0 ∈ 𝑁
std::array<unsigned, 1> successor(const std::array<unsigned, 1>& array)  {
    return {array[0] + 1};
}

// Projection basic function
// 𝑃𝑖𝑛: 𝑁𝑛 → 𝑁 
// (𝑥1,⋯, 𝑥𝑛) ∈ 𝑁𝑛 → 𝑃𝑖𝑛(𝑥1,⋯𝑥𝑛) = 𝑥𝑖, 𝑛 ≥ 1, 1 ≤ 𝑖 ≤ 𝑛
template<unsigned I, unsigned N>
std::array<unsigned, 1> projection(const std::array<unsigned, N>& array)  {
    static_assert(I <= N && I > 0);
    std::array<unsigned, 1> result;
    result[0] = array[I - 1];
    return result;
}

