#include <iostream>
#include <array>

#include "headers/combination.hpp"

using std::cout;

int main() {
    std::array<unsigned, 3> array1 = {1, 2, 3};
    std::array<unsigned, 2> array2 = {2, 3};
    std::array<unsigned, 5> array3 = combination<3, 2>(array1, array2);

    for (auto n : array3) {
        cout << n << std::endl;
    }
}