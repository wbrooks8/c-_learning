//
// Created by kyle on 10/27/26.
//

#include "lesson10.h"

#include <iostream>
#include <vector>

namespace lesson10 {
constexpr double pi{3.14159};

double convertToRadians(double degrees) { return degrees * pi / 180; }

// Avoid const_cast and reinterpret_cast unless you have a very good reason to
// use them.
int main() {
  // it is possible to have c++ deduce the type of a variable:
  // In cases where type is either hard to deduce or very long to type auto can
  // be helpful
  auto d2{5.0};   // 5.0 is a double literal, so d will be deduced as a double
  auto i2{1 + 2}; // 1 + 2 evaluates to an int, so i will be deduced as an int
  auto x2{i2};    // i is an int, so x will be deduced as an int

  typedef long Miles;      // Old way of creating a type alias
  using Distance = double; // define Distance as an alias for type double
  Distance milesToDestination{3.4}; // defines a variable of type double
  using VectPairSI =
      std::vector<std::pair<std::string, int>>; // Type alias is common on very
                                                // long type definitions.

  int x{10};
  int y{4};

  std::cout << (double)x / y << '\n'; // Avoid using C-style cast of x to double
  std::cout << double(x) / y << '\n'; // Function style cast to double

  char c{'a'};
  std::cout << static_cast<int>(c) << '\n';        // static cast is preferred.
  std::cout << static_cast<double>(x) / y << '\n'; // prints 2.5

  // a C-style string literal can't be converted to an int, so the following is
  // an invalid conversion int x { static_cast<int>("Hello") }; // invalid: will
  // produce compilation error

  int j{100};
  j = static_cast<int>(c / 2.5);
  using Degrees = double;
  using Radians = double;

  std::cout << "Enter a number of degrees: ";
  Degrees degrees{};
  std::cin >> degrees;

  Radians radians{convertToRadians(degrees)};
  std::cout << degrees << " degrees is " << radians << " radians.\n";

  return 0;

  return 0;
}
} // namespace lesson10