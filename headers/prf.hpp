#pragma once

#include <array>
#include <algorithm>

// PRF stands for primitive recursive function
template<unsigned SIZE1, unsigned SIZE2>
class PRF {
    public:
    PRF(); 
    virtual ~PRF(); 
    std::array<unsigned, SIZE2> operator()(
        const std::array<unsigned, SIZE1>& array
    ) const noexcept;
   
    protected:
    virtual std::array<unsigned, SIZE2> recursion_base_case(
        const std::array<unsigned, SIZE1 - 1>& array
    ) const noexcept = 0;
    virtual std::array<unsigned, SIZE2> recursion(
        const std::array<unsigned, SIZE1 + 1>& array
    ) const noexcept = 0;
    
};

template<unsigned SIZE1, unsigned SIZE2>
PRF<SIZE1, SIZE2>::PRF() {
    static_assert(SIZE1 > 0 && SIZE2 > 0);
}

template<unsigned SIZE1, unsigned SIZE2>
PRF<SIZE1, SIZE2>::~PRF() {}

template<unsigned SIZE1, unsigned SIZE2>
std::array<unsigned, SIZE2> PRF<SIZE1, SIZE2>::operator()(
    const std::array<unsigned, SIZE1>& array
) const noexcept {
    if (array[SIZE1 - 1] == 0) {
        std::array<unsigned, SIZE1 - 1> base_arg;
        std::copy(array.begin(), array.end() - 1, base_arg.begin());
        return recursion_base_case(base_arg);
    }
    std::array<unsigned, SIZE1> array_copy;
    std::copy(array.begin(), array.end() - 1, array_copy.begin());
    array_copy[SIZE1 - 1] = array[SIZE1 - 1];
    std::array<unsigned, SIZE1 + 1> recursion_arg;
    std::copy(array.begin(), array.end(), array_copy.begin());
    recursion_arg[SIZE1] = this->operator()(array_copy);
    return recursion(recursion_arg);
}