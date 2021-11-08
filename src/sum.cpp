#include "headers/sum.hpp"

std::array<unsigned, 1> Sum::recursion_base_case(
    const std::array<unsigned, 1>& array
) const noexcept {
    return projection<1, 1>(array);
}

std::array<unsigned, 1> Sum::recursion(
    const std::array<unsigned, 3>& array
) const noexcept {
    // Succesor function missing
    return projection<3, 3>(array);
}