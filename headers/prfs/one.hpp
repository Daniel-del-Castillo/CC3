#pragma once

#include "headers/prf_elements/prf.hpp"

// This PRF is really simple and could be considered
// unnecessary, nonetheless it was made to prove
// it is possible to represent PRF without using
// primitive recursion
class One : public PRF<1, 1>  {
   public:
    virtual std::array<unsigned, 1> operator()(
        const std::array<unsigned, 1>& array
    ) const override;
};