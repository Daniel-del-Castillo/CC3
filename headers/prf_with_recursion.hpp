#pragma once

#include <array>
#include <algorithm>

#include "headers/prf.hpp"

// This class represents the PRFs (Primitive Recursive Functions)
// that use primitive recursion. The separation in two classes is
// needed to enforce at compile time that PRF using primitive recursion
// can only return a single value, which is present in the formal
// definition of the primitive recursion.
//
// Formal definition:
// 𝑔: 𝑁𝑛 → 𝑁 
// ℎ: 𝑁𝑛+2 → 𝑁  
// Using:
// 𝑓: 𝑁𝑛+1 → 𝑁 
// 𝑋 = (𝑥1,⋯,𝑥𝑛) ∈ 𝑁𝑛  
// 𝑓(𝑋, 0) = 𝑔(𝑋)  
// 𝑓(𝑋, 𝑆(𝑦)) = ℎ(𝑋, 𝑦, 𝑓(𝑋, 𝑦))
template<unsigned N>
class PRFWithRecursion : public PRF<N, 1> {
    public:
    PRFWithRecursion(); 
    virtual ~PRFWithRecursion(); 
    std::array<unsigned, 1> operator()(
        const std::array<unsigned, N>& array
    ) const override;
   
    protected:
    virtual std::array<unsigned, 1> recursion_base_case(
        const std::array<unsigned, N - 1>& array
    ) const = 0;
    virtual std::array<unsigned, 1> recursion(
        const std::array<unsigned, N + 1>& array
    ) const = 0;
    
};


template<unsigned N>
PRFWithRecursion<N>::~PRFWithRecursion() {}

template<unsigned N>
std::array<unsigned, 1> PRFWithRecursion<N>::operator()(
    const std::array<unsigned, N>& array
) const {
    if (array[N - 1] == 0) {
        std::array<unsigned, N - 1> base_arg;
        std::copy(array.begin(), array.end() - 1, base_arg.begin());
        return recursion_base_case(base_arg);
    }
    std::array<unsigned, N> array_copy;
    std::copy(array.begin(), array.end() - 1, array_copy.begin());
    array_copy[N - 1] = array[N - 1] - 1;

    std::array<unsigned, N + 1> recursion_arg;
    std::copy(array_copy.begin(), array_copy.end(), recursion_arg.begin());
    recursion_arg[N] = this->operator()(array_copy)[0];
    return recursion(recursion_arg);
}