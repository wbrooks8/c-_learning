//
// Created by mymus on 11/10/2026.
//

#include "lesson17.h"

#include <array>
#include <iostream>
#include <vector>

namespace lesson17 {
    void runLesson() {
        constexpr std::array<int, 5> a{}; // a std::array of 5 ints

        constexpr int len{8};
        constexpr std::array<int, len> b{}; // Using a constexpr variable

        enum Colors {
            red,
            green,
            blue,
            max_colors
        };

        constexpr std::array<int, max_colors> c{}; // Using an enumerator

        const std::vector<int> b2(5); // a std::vector of 5 ints (for comparison)
        constexpr std::array<int, 6> fibonnaci = {0, 1, 1, 2, 3, 5}; // copy-list initialization using braced list

        constexpr std::array<int, 5> prime{2, 3, 5, 7, 11}; // list initialization using braced list (preferred)
        constexpr std::array<int, 4> b3{1, 2}; // b[2] and b[3] are value initialized

        constexpr std::array a1 { 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
        constexpr std::array a2 { 9.7, 7.31 };     // The type is deduced to std::array<double, 2>

        constexpr std::array<double, 365> high{};

        constexpr std::array arr {'h', 'e', 'l', 'l', 'o'};
        std::cout << arr[0] << '\n';
        std::cout << "The length is " << std::size(arr) << '\n';
        std::cout << arr[1] << arr.at(1) << std::get<1>(arr) << '\n';
    }
}
