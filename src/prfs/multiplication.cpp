#include "headers/prfs/multiplication.hpp"

std::array<unsigned, 1> Multiplication::recursion_base_case(
    const std::array<unsigned, 1>& array
) const  {
    return projection<1, 1>(array);
}

std::array<unsigned, 1> Multiplication::recursion(
    const std::array<unsigned, 3>& array
) const {
    return composition<3, 2, 1>(
        PRF_to_fn<2, 1, Sum>(),
        combination<3, 1, 1>(projection<1, 3>, projection<3, 3>)
    )(array);
}