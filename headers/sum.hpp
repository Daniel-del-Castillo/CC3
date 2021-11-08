#pragma once

#include "headers/prf.hpp"

class Sum : public PRF<2, 1>  {
   protected:
    virtual std::array<unsigned, 1> recursion_base_case(
        const std::array<unsigned, 1>& array
    ) const noexcept override;
    virtual std::array<unsigned, 1> recursion(
        const std::array<unsigned, 3>& array
    ) const noexcept override;
};