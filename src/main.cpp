#include <iostream>
#include <array>

#include "headers/prf_with_recursion.hpp"

using std::cout;

std::array<unsigned, 5> bigger(std::array<unsigned, 2> array) {
    std::array<unsigned, 5> result;
    for (auto i = 0; i < 2; i++) {
        result[i] = array[i];
    }
    for (auto i = 0; i < 3; i++) {
        result[i + 2] = i;
    }
    return result;
}

std::array<unsigned, 3> smaller(std::array<unsigned, 5> array) {
    std::array<unsigned, 3> result;
    for (auto i = 0; i < 3; i++) {
        result[i] = array[i];
    }
    return result;
}

int main() {
    std::array<unsigned, 2> array2 = {2, 3};
    auto bigger_fn = bigger;
    auto smaller_fn = smaller;
    auto function = composition<2, 5, 3>(smaller_fn, bigger_fn);
    auto array3 = function(array2);
    auto result = projection<1, 3>(array3);

    for (auto n : result) {
        cout << n << std::endl;
    }
}