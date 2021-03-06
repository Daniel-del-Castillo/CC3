#pragma once

#include "headers/prf_elements/prf_with_recursion.hpp"

class Sum : public PRFWithRecursion<2>  {
   protected:
    std::array<unsigned, 1> recursion_base_case(
        const std::array<unsigned, 1>& array
    ) const override;
    std::array<unsigned, 1> recursion(
        const std::array<unsigned, 3>& array
    ) const override;
};