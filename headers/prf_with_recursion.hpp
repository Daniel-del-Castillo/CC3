#pragma once

#include <array>
#include <algorithm>

#include "headers/prf.hpp"

// This class represents the PRFs (Primitive Recursive Functions)
// that use primitive recursion. The separation in two classes is
// needed to enforce at compile time that PRF using primitive recursion
// can only return a single value, which is present in the formal
// definition of the primitive recursion.
template<unsigned SIZE>
class PRFWithRecursion : public PRF<SIZE, 1> {
    public:
    PRFWithRecursion(); 
    virtual ~PRFWithRecursion(); 
    std::array<unsigned, 1> operator()(
        const std::array<unsigned, SIZE>& array
    ) const noexcept override;
   
    protected:
    virtual std::array<unsigned, 1> recursion_base_case(
        const std::array<unsigned, SIZE - 1>& array
    ) const noexcept = 0;
    virtual std::array<unsigned, 1> recursion(
        const std::array<unsigned, SIZE + 1>& array
    ) const noexcept = 0;
    
};


template<unsigned SIZE>
PRFWithRecursion<SIZE>::~PRFWithRecursion() {}

template<unsigned SIZE>
std::array<unsigned, 1> PRFWithRecursion<SIZE>::operator()(
    const std::array<unsigned, SIZE>& array
) const noexcept {
    if (array[SIZE - 1] == 0) {
        std::array<unsigned, SIZE - 1> base_arg;
        std::copy(array.begin(), array.end() - 1, base_arg.begin());
        return recursion_base_case(base_arg);
    }
    std::array<unsigned, SIZE> array_copy;
    std::copy(array.begin(), array.end() - 1, array_copy.begin());
    array_copy[SIZE - 1] = array[SIZE - 1] - 1;

    std::array<unsigned, SIZE + 1> recursion_arg;
    std::copy(array_copy.begin(), array_copy.end(), recursion_arg.begin());
    recursion_arg[SIZE] = this->operator()(array_copy);
    return recursion(recursion_arg);
}