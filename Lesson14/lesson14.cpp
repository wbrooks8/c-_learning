//
// Created by kyle on 11/4/26.
//

#include "lesson14.h"

#include <iostream>

namespace lesson14 {
class Date // we changed struct to class
{
public:        // and added this line, which is called an access specifier
  int m_day{}; // and added "m_" prefixes to each of the member names
  int m_month{};
  int m_year{};
};

class Employee {
  std::string m_name{};

public:
  Employee(std::string name) { std::cout << "Employee()" << std::endl; };

  void setName(std::string_view name) { m_name = name; }

  const std::string &getName() const {
    return m_name;
  } //  getter returns by const reference. Type should match returned object.
};

void printDate(const Date &date) {
  std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
}

int runLesson() {
  Date date{4, 10, 21};
  printDate(date);

  Employee Joe {"Joe"}; // joe exists until end of function
  Joe.setName("Joe");

  std::cout << Joe.getName(); // returns joe.m_name by reference

  return 0;
}
} // namespace lesson14