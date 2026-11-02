//
// Created by kyle on 10/30/26.
//

#include "lesson12.h"

#include <iostream>
#include <optional>

// The & symbol tends to cause confusion because it has different meanings
// depending on context:

// When following a type name, & denotes an lvalue reference: int& ref.
// When used in a unary context in an expression, & is the address-of operator:
// std::cout << &x. When used in a binary context in an expression, & is the
// Bitwise AND operator: std::cout << x & y.

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

  std::cout << "The two fractions multiplied: " << num1 * num2 << '/'
            << den1 * den2 << '\n';

  return 0;
}

void printValue(std::string &y) { // Passing in a refence instead of creating a
                                  // whole new variable in memory
  std::cout << y << '\n';
}

// Our function now optionally returns an int value
std::optional<int> doIntDivision(int x, int y)
{
  if (y == 0)
    return {}; // or return std::nullopt
  return x / y;
}

void sort2(int& x, int& y) {
  if (x > y) {
    std::swap(x, y);
  }
}

void runLesson() {
  //     Lvalue expressions evaluate to an identifiable object.
  //     Rvalue expressions evaluate to a value.

  //     A rule of thumb to identify lvalue and rvalue expressions:
  //
  //      Lvalue expressions are those that evaluate to functions or
  //      identifiable objects (including variables) that persist beyond the end
  //      of the expression. Rvalue expressions are those that evaluate to
  //      values, including literals and temporary objects that do not persist
  //      beyond the end of the expression.
  int x{5};
  int y{x}; // x is an lvalue expression, x is a modifiable lvalue expression
  const double d{1.2}; // 1.2 is an rvalue expression
  const double e{d};   // d is a non-modifiable lvalue expression

  std::cout << x << '\n';  // print the value of variable x
  std::cout << &x << '\n'; // print the memory address of variable x

  std::cout << *(&x)
            << '\n'; // print the value at the memory address of variable x
                     // (parentheses not required, but make it easier to read)

  int &ref{x};  // Creates reference to 'x'
  int *ptr{&x}; // a pointer to an integer

  int *ptr2{
      nullptr}; // can use nullptr to initialize a pointer to be a null pointer

  // Assume ptr is some pointer that may or may not be a null pointer
  if (ptr) // if ptr is not a null pointer
    std::cout << *ptr << '\n'; // okay to dereference
  else
    // do something else that doesn't involve dereferencing ptr (print an error message, do nothing at all, etc...)

  std::cout
      << *ptr
      << '\n'; // print the value at the address being pointed to (x's address)

  std::string stringRef{"Hello World!"};

  printValue(stringRef);

  std::optional<int> result1 { doIntDivision(20, 5) };
  if (result1) // if the function returned a value
    std::cout << "Result 1: " << *result1 << '\n'; // get the value
  else
    std::cout << "Result 1: failed\n";

  std::optional<int> result2 { doIntDivision(5, 0) };

  if (result2)
    std::cout << "Result 2: " << *result2 << '\n';
  else
    std::cout << "Result 2: failed\n";

  int x2 { 7 };
  int y2 { 5 };

  std::cout << x2 << ' ' << y2 << '\n'; // should print 7 5

  sort2(x2, y2); // make sure sort works when values need to be swapped
  std::cout << x2 << ' ' << y2 << '\n'; // should print 5 7

  sort2(x2, y2); // make sure sort works when values don't need to be swapped
  std::cout << x2 << ' ' << y2 << '\n'; // should print 5 7
}
} // namespace lesson12
