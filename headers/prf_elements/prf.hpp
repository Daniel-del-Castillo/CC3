#pragma once

#include <array>
#include <algorithm>
#include <functional>

#include "headers/prf_elements/combination.hpp"
#include "headers/prf_elements/composition.hpp"
#include "headers/prf_elements/basic_functions.hpp"

// PRF stands for primitive recursive function
// The idea behind this class is that anyone could make a derived
// class that, thanks to this class and the other operators and basic 
// functions defined in this project, allows writing a PRF using only 
// the same elements you would use in paper. For that they would only need
// to override the () operator. If primitive recursion is needed 
// PRFWithRecursion should be useful.
//
// Keep in mind that this approach only tries to mimic theoric PRFs as closely
// as possible, efficiency is explicitly not an objective of this project
// so don't expect the execution to be fast.
//
// Formal definition:
// 𝑓: 𝑁𝑛 → 𝑁𝑚 
template<unsigned N, unsigned M>
class PRF {
    public:
    PRF(); 
    virtual ~PRF(); 
    virtual std::array<unsigned, M> operator()(
        const std::array<unsigned, N>& array
    ) const  = 0;
};

template<unsigned N, unsigned M>
PRF<N, M>::PRF() {
    static_assert(N > 0 && M > 0);
}

template<unsigned N, unsigned M>
PRF<N, M>::~PRF() {}

// This function allows to convert a PRF class as a function.
// This is needed to use the user defined PRFs in a compositions
// or combinations.
// The class used in the C template *MUST* be derived from PRF
template<unsigned N, unsigned M, class C>
fn<N, M> PRF_to_fn() {
    return [&]
        (const std::array<unsigned, N>& array)
        -> std::array<unsigned, M> {
        C instance;
        return instance(array);
    };
}