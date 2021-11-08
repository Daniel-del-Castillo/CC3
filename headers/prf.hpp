#pragma once

#include <array>
#include <algorithm>

#include "headers/combination.hpp"
#include "headers/composition.hpp"
#include "headers/projection.hpp"

// PRF stands for primitive recursive function
template<unsigned SIZE1, unsigned SIZE2>
class PRF {
    public:
    PRF(); 
    virtual ~PRF(); 
    virtual std::array<unsigned, SIZE2> operator()(
        const std::array<unsigned, SIZE1>& array
    ) const noexcept = 0;
};

template<unsigned SIZE1, unsigned SIZE2>
PRF<SIZE1, SIZE2>::PRF() {
    static_assert(SIZE1 > 0 && SIZE2 > 0);
}

template<unsigned SIZE1, unsigned SIZE2>
PRF<SIZE1, SIZE2>::~PRF() {}
