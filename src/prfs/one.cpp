#include "headers/prfs/one.hpp"

std::array<unsigned, 1> One::operator()(
    const std::array<unsigned, 1>& array
) const {
    return composition<1, 1, 1>(
        successor,
        zero
    )(array);
}