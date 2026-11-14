//
// Created by mymus on 11/13/2026.
//

#include "lesson19.h"

#include <iostream>
#include <new>

namespace lesson19 {
    void memoryLeak() {
        // Memory Leak
        // int value = 5;
        // int* ptr{ new int{} }; // allocate memory
        // ptr = &value; // old address lost, memory leak results

        // Fix
        int value{ 5 };
        int* ptr{ new int{} }; // allocate memory
        delete ptr; // return memory back to operating system
        ptr = &value; // reassign pointer to address of value
    }
    void runLesson() {
        int *ptr{new int}; // dynamically allocate an integer and assign the address to ptr so we can access it later
        *ptr = 7; // assign value of 7 to allocated memory
        int* ptr1{ new int (5) }; // use direct initialization
        int* ptr2{ new int { 6 } }; // use uniform initialization

        // assume ptr has previously been allocated with operator new
        delete ptr; // return the memory pointed to by ptr to the operating system
        ptr = nullptr; // set ptr to be a null pointer

        int* value { new (std::nothrow) int }; // value will be set to a null pointer if the integer allocation fails
        if (!value) // handle case where new returned null
        {
            // Do error handling here
            std::cerr << "Could not allocate memory\n";
        }
        // If ptr isn't already allocated, allocate it
        if (!ptr)
            ptr = new int;

        std::cout << "Enter a positive integer: ";
        size_t size{};
        std::cin >> size;

        int* array2{ new int[size]{} };

        std::cout << "I just allocated an array of integers of length " << size << '\n';

        array2[0] = 5;

        delete[] array2;

        array2 = nullptr;

        int fixedArray[5] = { 9, 7, 5, 3, 1 }; // initialize a fixed array before C++11
        int* array{ new int[5]{ 9, 7, 5, 3, 1 } }; // initialize a dynamic array since C++11
        // To prevent writing the type twice, we can use auto. This is often done for types with long names.
        auto* array3{ new int[5]{ 9, 7, 5, 3, 1 } };
        int fixedArray2[]{ 9, 7, 5, 3, 1 }; // initialize a fixed array in C++11
        char fixedArray3[]{ "Hello, world!" }; // initialize a fixed array in C++11
    }
} // lesson19
