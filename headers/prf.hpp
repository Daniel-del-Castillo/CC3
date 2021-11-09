#pragma once

#include <array>
#include <algorithm>

#include "headers/combination.hpp"
#include "headers/composition.hpp"
#include "headers/basic_functions.hpp"

// PRF stands for primitive recursive function
// The idea behind this class is that anyone could make a derived
// class that, thanks to this class and the other operators and basic 
// functions defined in this project, allows to write a PRF using only 
// the same elements you would use in paper. For that they would only need
// to override the () operator. If primitive recursion is needed 
// PRFWithRecursion should be useful.
template<unsigned SIZE1, unsigned SIZE2>
class PRF {
    public:
    PRF(); 
    virtual ~PRF(); 
    virtual std::array<unsigned, SIZE2> operator()(
        const std::array<unsigned, SIZE1>& array
    ) const  = 0;
};

template<unsigned SIZE1, unsigned SIZE2>
PRF<SIZE1, SIZE2>::PRF() {
    static_assert(SIZE1 > 0 && SIZE2 > 0);
}

template<unsigned SIZE1, unsigned SIZE2>
PRF<SIZE1, SIZE2>::~PRF() {}
