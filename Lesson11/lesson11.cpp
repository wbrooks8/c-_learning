//
// Created by kyle on 10/27/26.
//

#include "lesson11.h"

#include <iostream>
#include <ostream>

namespace lesson11 {
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
int main() {
  std::cout << add(1, 2) << std::endl;
  std::cout << add(1.1, 2.2) << std::endl;
  return 0;
}
} // namespace lesson11