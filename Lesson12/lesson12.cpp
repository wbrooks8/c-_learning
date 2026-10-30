//
// Created by kyle on 10/30/26.
//

#include "lesson12.h"

#include <iostream>

namespace lesson12 {
int multiplyFractions() {
  // Our first fraction
  int num1 {};
  int den1 {};

  // Our second fraction
  int num2 {};
  int den2 {};

  // Used to eat (remove) the slash between the numerator and denominator
  char ignore {};

  std::cout << "Enter a fraction: ";
  std::cin >> num1 >> ignore >> den1;

  std::cout << "Enter a fraction: ";
  std::cin >> num2 >> ignore >> den2;

  std::cout << "The two fractions multiplied: "
      << num1 * num2 << '/' << den1 * den2 << '\n';

  return 0;
}
void runLesson() {

}
} // lesson12