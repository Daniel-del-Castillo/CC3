#include "headers/prfs/power.hpp"

std::array<unsigned, 1> Power::recursion_base_case(
    const std::array<unsigned, 1>& array
) const  {
    return composition<1, 1, 1>(
        successor,
        zero
    )(array);
}

std::array<unsigned, 1> Power::recursion(
    const std::array<unsigned, 3>& array
) const {
    return composition<3, 2, 1>(
        PRF_to_fn<2, 1, Multiplication>(),
        combination<3, 1, 1>(projection<1, 3>, projection<3, 3>)
    )(array);
}