//
// Created by kyle on 10/27/26.
//

#include "lesson11.h"

#include <iostream>
#include <ostream>

namespace lesson11 {
    // This function will take precedence for arguments of type int
    void printInt(int x) {
        std::cout << x << '\n';
    }

    void printInt(char) = delete; // calls to this function will halt compilation
    void printInt(bool) = delete; // calls to this function will halt compilation'

    // This function template will take precedence for arguments of other types
    // Since this function template is deleted, calls to it will halt compilation
    template<typename T>
    void printInt(T x) = delete;

    int add(int a, int b) { return a + b; }

    double add(double a, double b) { return a + b; }

    int main() {
        std::cout << add(1, 2) << std::endl;
        std::cout << add(1.1, 2.2) << std::endl;
        return 0;
    }
} // namespace lesson11
