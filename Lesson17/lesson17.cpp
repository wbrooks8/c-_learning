//
// Created by mymus on 11/10/2026.
//

#include "lesson17.h"

#include <array>
#include <iostream>
#include <vector>

struct House {
  int number{};
  int stories{};
  int roomsPerStory{};
};

namespace lesson17 {
void defineHouses() {
  std::array<House, 3> houses{};

  houses[0] = {13, 1, 7};
  houses[1] = {14, 2, 5};
  houses[2] = {15, 2, 4};

  constexpr std::array<House, 3> houses2{
      // initializer for houses
      {
          // extra set of braces to initialize the C-style array member with
          // implementation_defined_name
          {13, 4, 30}, // initializer for array element 0
          {14, 3, 10}, // initializer for array element 1
          {15, 3, 40}, // initializer for array element 2
      }};

  for (const auto &house : houses) {
    std::cout << "House number " << house.number << " has "
              << (house.stories * house.roomsPerStory) << " rooms.\n";
  }
}

namespace Color {
enum Type { black, red, blue, max_colors };

// use sv suffix so std::array will infer type as std::string_view
using namespace std::string_view_literals; // for sv suffix
constexpr std::array colorName{"black"sv, "red"sv, "blue"sv};

// Make sure we've defined strings for all our colors
static_assert(std::size(colorName) == max_colors);
}; // namespace Color

constexpr std::string_view getColorName(Color::Type color) {
  // We can index the array using the enumerator to get the name of the
  // enumerator
  return Color::colorName[static_cast<std::size_t>(color)];
}

// Teach operator<< how to print a Color
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from
// being made)!
std::ostream &operator<<(std::ostream &out, Color::Type color) {
  return out << getColorName(color);
}

// Teach operator>> how to input a Color by name
// We pass color by non-const reference so we can have the function modify its
// value
std::istream &operator>>(std::istream &in, Color::Type &color) {
  std::string input{};
  std::getline(in >> std::ws, input);

  // Iterate through the list of names to see if we can find a matching name
  for (std::size_t index = 0; index < Color::colorName.size(); ++index) {
    if (input == Color::colorName[index]) {
      // If we found a matching name, we can get the enumerator value based on
      // its index
      color = static_cast<Color::Type>(index);
      return in;
    }
  }

  // We didn't find a match, so input must have been invalid
  // so we will set input stream to fail state
  in.setstate(std::ios_base::failbit);

  // On an extraction failure, operator>> zero-initializes fundamental types
  // Uncomment the following line to make this operator do the same thing
  // color = {};
  return in;
}

int colorLesson() {
  auto shirt{Color::blue};
  std::cout << "Your shirt is " << shirt << '\n';

  std::cout << "Enter a new color: ";
  std::cin >> shirt;
  if (!std::cin)
    std::cout << "Invalid\n";
  else
    std::cout << "Your shirt is now " << shirt << '\n';

  return 0;
}

void printElementZero(const int arr[]) // treated the same as const int*
{
  std::cout << arr[0] << std::endl;
}

void runLesson() {
  constexpr std::array<int, 5> a{}; // a std::array of 5 ints

  constexpr int len{8};
  constexpr std::array<int, len> b{}; // Using a constexpr variable

  enum Colors { red, green, blue, max_colors };

  constexpr std::array<int, max_colors> c{}; // Using an enumerator

  const std::vector<int> b2(5); // a std::vector of 5 ints (for comparison)
  constexpr std::array<int, 6> fibonnaci = {
      0, 1, 1, 2, 3, 5}; // copy-list initialization using braced list

  constexpr std::array<int, 5> prime{
      2, 3, 5, 7, 11}; // list initialization using braced list (preferred)
  constexpr std::array<int, 4> b3{1, 2}; // b[2] and b[3] are value initialized

  constexpr std::array a1{9, 7, 5, 3,
                          1}; // The type is deduced to std::array<int, 5>
  constexpr std::array a2{9.7,
                          7.31}; // The type is deduced to std::array<double, 2>

  constexpr std::array<double, 365> high{};

  constexpr std::array arr{'h', 'e', 'l', 'l', 'o'};
  std::cout << arr[0] << '\n';
  std::cout << "The length is " << std::size(arr) << '\n';
  std::cout << arr[1] << arr.at(1) << std::get<1>(arr) << '\n';

  colorLesson();

  int testScore[30] {};      // Defines a C-style array named testScore that contains 30 value-initialized int elements (no include required)
  int prime2[5] { 2, 3, 5, 7, 11 };         // list initialization using braced list (preferred)
  int arr2[5] {}; // Members value initialized (int elements are zero uninitialized) (preferred)
  const int prime3[] { 2, 3, 5, 7, 11 };  // prime2 deduced by compiler to have length 5
  constexpr int a3[3] {};

  std::cout << std::size(prime2) << '\n';  // C++17, returns unsigned integral value 5
  std::cout << std::ssize(prime2) << '\n'; // C++20, returns signed integral value 5

  const int squares[] { 1, 4, 9, 25, 36, 49, 64, 81 };

  printElementZero(prime2);  // prime decays to a pointer
  printElementZero(squares); // squares decays to a pointer

}
} // namespace lesson17
