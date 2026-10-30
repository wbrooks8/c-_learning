//
// Created by kyle on 10/27/26.
//

#include "lesson11.h"

#include <iostream>
#include <ostream>

namespace lesson11 {

// This function will take precedence for arguments of type int
void printInt(int x) { std::cout << x << '\n'; }

// This function template will take precedence for arguments of other types
// Since this function template is deleted, calls to it will halt compilation
template <typename T> void printInt(T x) = delete;

void printInt(char) = delete; // calls to this function will halt compilation
void printInt(bool) = delete; // calls to this function will halt compilation

void print(int x, int y = 10) // 10 is the default argument
{
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n';
}

// Standard function definition
int max(int x, int y) { return (x < y) ? y : x; }

// Template function definition.
template <typename T> // this is the template parameter declaration defining T
                      // as a type template parameter
T max(T x, T y)       // this is the function template
                      // definition for max<T>
{
  return (x < y) ? y : x;
}
// To call this function in int values we would do this:
// max<int>(1, 2)
// We can make the compiler try to infer the types using this syntax:
// std::cout << max<>(1, 2) << '\n';
// std::cout << max(1, 2) << '\n'; // This the preferred way to call template
// functions.

template <typename T> T addOne(T x) { return x + 1; }

// Use function template specialization to tell the compiler that addOne(const
// char*) should emit a compilation error const char* will match a string
// literal
template <> const char *addOne(const char *x) = delete;

// We can call with two different type values using the following example:
template <typename T, typename U>
auto max(T x,
         U y) // The compiler can figure out what the relevant return type is
{
  return (x < y) ? y : x;
}

// C++20 allows an abbreviated version:
auto max20(auto x, auto y) { return (x < y) ? y : x; }

template <auto N> // deduce non-type template parameter from template argument
void print() {
  std::cout << N << '\n';
}

template <int N> constexpr int factorial() {
  static_assert(N >= 0);

  int product{1};
  for (int i{2}; i <= N; ++i)
    product *= i;

  return product;
}

auto mult(auto x, int y) {
  return (x * y);
}

auto sub(auto x, auto y) { return x - y; }

auto add(auto x, auto y) { return x + y; }
int main() {
  std::cout << add(1, 2) << std::endl;
  std::cout << add(1.1, 2.2) << std::endl;

  std::cout << mult(2, 3) << '\n';
  std::cout << mult(1.2, 3) << '\n';

  std::cout << sub(3, 2) << '\n';
  std::cout << sub(3.5, 2) << '\n';
  std::cout << sub(4, 1.5) << '\n';

  print(1, 2); // y will use user-supplied argument 2
  print(3);    // y will use default argument 4, as if we had called print(3, 4)

  static_assert(factorial<0>() == 1);
  static_assert(factorial<3>() == 6);
  static_assert(factorial<5>() == 120);

  return 0;
}
} // namespace lesson11