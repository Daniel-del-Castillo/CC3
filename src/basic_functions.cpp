#include "headers/prf_elements/basic_functions.hpp"

std::array<unsigned, 1> zero(const std::array<unsigned, 1>& array)  {
    return {0};
}

std::array<unsigned, 1> successor(const std::array<unsigned, 1>& array)  {
    return {array[0] + 1};
}