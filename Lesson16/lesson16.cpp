//
// Created by mymus on 11/7/2026.
//

#include "lesson16.h"

#include <iostream>
#include <vector>

namespace lesson16 {
    template<typename T>
    void passByRef(const std::vector<T> &arr) {
        std::cout << arr[0] << '\n';
    }

    void passByRefAuto(const auto &arr) // abbreviated function template
    {
        std::cout << arr[0] << '\n';
    }

    // index needs to be an int, not a std::size_t, otherwise we won't be able to detect if the user passes in a negative index
    template <typename T>
    void printElement(const std::vector<T>& arr, int index)
    {
        if (index < 0 || index >= static_cast<int>(arr.size())) // In C++20, could use std::ssize(arr) to avoid the cast
            std::cout << "Invalid index\n";
        else
            std::cout << "The element has value " << arr[static_cast<std::size_t>(index)] << '\n';
    }

    void runLesson() {
        std::vector<int> sampleV{};
        std::vector<int> primes{2, 3, 5, 7};
        std::vector<int> data(10); // vector containing 10 int elements, value-initialized to 0


        std::vector<int> arr(3); // create a vector of length 3

        // std::cout << "Enter 3 integers: ";
        // std::cin >> arr[0] >> arr[1] >> arr[2];

        std::cout << "The sum is: " << arr[0] + arr[1] + arr[2] << '\n';
        std::cout << "The product is: " << arr[0] * arr[1] * arr[2] << '\n';

        std::vector<char> hello{'h', 'e', 'l', 'l', 'o'};

        std::cout << hello.size() << '\n';
        std::cout << hello[1] << hello.at(1) << '\n';

        passByRef(primes);
        passByRef(hello);
    }
} // lesson16
