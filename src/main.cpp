#include <iostream>
#include <array>

#include "headers/combination.hpp"
#include "headers/composition.hpp"

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
    auto function = composition<2, 5, 3>(bigger_fn, smaller_fn);
    auto array3 = function(array2);

    for (auto n : array3) {
        cout << n << std::endl;
    }
}