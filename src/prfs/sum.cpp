#include "headers/prfs/sum.hpp"

std::array<unsigned, 1> Sum::recursion_base_case(
    const std::array<unsigned, 1>& array
) const  {
    return projection<1, 1>(array);
}

std::array<unsigned, 1> Sum::recursion(
    const std::array<unsigned, 3>& array
) const {
    return composition<3, 1, 1>(successor, projection<3, 3>)(array);
}