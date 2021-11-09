#include <iostream>
#include <array>
#include <string>
#include <optional>
#include <stdexcept>

#include "headers/prfs/power.hpp"

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::optional;
using std::nullopt;
using std::stoi;
using std::exception;
using std::array;

optional<unsigned> read_number() {
    string s;
    getline(cin, s);
    int result;
    try {
        result = stoi(s);
    } catch (const exception& e) {
        return nullopt;
    }
    if (result < 0) {
        return nullopt;
    }
    return optional<unsigned>{(unsigned)result};
}

int main() {
    cout << "This program calculates powers with a primitive ";
    cout << "recursive function like architecture:\n";
    cout << "Write anything other than a natural number for exiting\n\n";
    Power power_prf;
    while (true) {
        array<unsigned, 2> input;
        cout << "Enter the base: ";
        auto base = read_number();
        if (!base.has_value()) {
            break;
        }
        input[0] = *base;
        cout << "Enter the power: ";
        auto power = read_number();
        if (!power.has_value()) {
            break;
        }
        input[1] = *power;
        cout << "The result is: " << power_prf(input)[0] << "\n\n";
    }
    cout << "Exiting the program\n";
}