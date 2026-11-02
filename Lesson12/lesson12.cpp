//
// Created by kyle on 10/30/26.
//

#include "lesson12.h"

#include <iostream>

namespace lesson12 {
    int multiplyFractions() {
        // Our first fraction
        int num1{};
        int den1{};

        // Our second fraction
        int num2{};
        int den2{};

        // Used to eat (remove) the slash between the numerator and denominator
        char ignore{};

        std::cout << "Enter a fraction: ";
        std::cin >> num1 >> ignore >> den1;

        std::cout << "Enter a fraction: ";
        std::cin >> num2 >> ignore >> den2;

        std::cout << "The two fractions multiplied: "
                << num1 * num2 << '/' << den1 * den2 << '\n';

        return 0;
    }

    void printValue(std::string& y) { //Passing in a refence instead of creating a whole new variable in memory
        std::cout << y << '\n';
    }

    void runLesson() {
        //     Lvalue expressions evaluate to an identifiable object.
        //     Rvalue expressions evaluate to a value.

        //     A rule of thumb to identify lvalue and rvalue expressions:
        //
        //      Lvalue expressions are those that evaluate to functions or identifiable objects (including variables) that persist beyond the end of the expression.
        //      Rvalue expressions are those that evaluate to values, including literals and temporary objects that do not persist beyond the end of the expression.
        int x{5};
        int y{x}; // x is an lvalue expression, x is a modifiable lvalue expression
        const double d{1.2}; // 1.2 is an rvalue expression
        const double e{d}; // d is a non-modifiable lvalue expression

        int &ref{x}; // Creates reference to 'x'

        std::string stringRef{"Hello World!"};

        printValue(stringRef);
    }
} // lesson12
