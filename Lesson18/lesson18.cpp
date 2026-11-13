//
// Created by kyle on 11/13/26.
//

#include "lesson18.h"
#include <algorithm> // for std::sort
#include <array>
#include <iostream>
#include <iterator> // for std::size

namespace lesson18 {

void bubble(int array[], int size) {
  // Proper bubble sort implementation
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
      }
    }
  }

  std::cout << array << std::endl;
}

bool containsNut(std::string_view str)
{
  return str.find("nut") != std::string_view::npos;
}

void runLesson()
{
  int array[]{ 30, 50, 20, 10, 40 };

  bubble(array, 5);

  for (int i{ 0 }; i < static_cast<int>(std::size(array)); ++i)
    std::cout << array[i] << ' ';

  std::cout << '\n';

  std::array<std::string_view, 5> arr{ "apple", "banana", "walnut", "lemon", "peanut" };

  auto nuts{ std::count_if(arr.begin(), arr.end(), containsNut) };

  std::cout << "Counted " << nuts << " nut(s)\n";

}
}