//
// Created by kyle on 11/2/26.
//

#include <cstdint>

#include "lesson13.h"

#include <algorithm>
#include <iostream>
#include <optional>
#include <string_view>

namespace lesson13 {
// Define a new unscoped enumeration named Color
// Use an 8-bit integer as the enum underlying type
enum class Color : std::int8_t {
  // Here are the enumerators
  // These symbolic constants define all the possible values this type can hold
  // Each enumerator is separated by a comma, not a semicolon
  red,
  green,
  blue, // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

// 1 way to get the string version of our enumerator
constexpr std::string_view getColorName(Color color) {
  switch (color) {
  case Color::green:
    return "green";
  case Color::red:
    return "red";
  case Color::blue:
    return "blue";
  default:
    return "???";
  }
}

// 2nd and preferred way to get a string version of our enumerator
constexpr std::optional<Color> getColorFromString(std::string_view colorName) {
  if (colorName == "green") {
    return Color::green;
  }
  if (colorName == "red") {
    return Color::red;
  }
  if (colorName == "blue") {
    return Color::blue;
  }

  return {};
}

std::string toASCIILowerCase(std::string_view sv) {
  std::string lower{};
  std::transform(sv.begin(), sv.end(), std::back_inserter(lower), [](char c) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  });
  return lower;
}

// Teach operator<< how to print a Color
// std::ostream is the type of std::cout, std::cerr, etc...
// The return type and parameter type are references (to prevent copies from
// being made)
std::ostream &operator<<(std::ostream &out, Color color) {
  out << getColorName(
      color); // print our color's name to whatever output stream out
  return out; // operator<< conventionally returns its left operand

  // The above can be condensed to the following single line:
  // return out << getColorName(color)
}

// pet is an in/out parameter
std::istream &operator>>(std::istream &in, Color &color) {
  std::string s{};
  in >> s; // get input string from user

  std::optional<Color> match{getColorFromString(s)};
  if (match) // if we found a match
  {
    color = *match; // dereference std::optional to get matching enumerator
    return in;
  }

  // We didn't find a match, so input must have been invalid
  // so we will set input stream to fail state
  in.setstate(std::ios_base::failbit);

  // On an extraction failure, operator>> zero-initializes fundamental types
  // Uncomment the following line to make this operator do the same thing
  // pet = {};

  return in;
}

// Creates a stucture for Employees
struct Employee {
  int id {};
  int age {};
  double wage{};
};

// Overloaded out operator to print Employee
std::ostream& operator<<(std::ostream& out, const Employee& e)
{
  out << "id: " << e.id << " age: " << e.age << " wage: " << e.wage;
  return out;
}

// Creating a template struct:
template <typename T>
struct Pair
{
  T first{};
  T second{};
};

template <typename T>
constexpr T max(Pair<T> p)
{
  return (p.first < p.second ? p.second : p.first);
}

int runLesson() {
  // Define a few variables of enumerated type Color
  Color apple{Color::red};   // my apple is red
  Color shirt{Color::green}; // my shirt is green
  Color cup{Color::blue};    // my cup is blue

  std::cout << "Enter a color: red, green, blue: ";
  std::string s{};
  std::cin >> s;

  s = toASCIILowerCase(s);

  std::cout << "Your shirt is " << shirt << '\n'; // it works!

  std::optional<Color> color{getColorFromString(s)};

  if (!color)
    std::cout << "You entered an invalid color\n";
  else
    std::cout << "You entered: " << getColorName(*color) << '\n';

  std::cout << "Enter a color: red, green, blue: ";
  Color color2{};
  std::cin >> color2;

  if (std::cin) // if we found a match
    std::cout << "You chose: " << getColorName(color2) << '\n';
  else {
    std::cin.clear(); // reset the input stream to good
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Your pet was not valid\n";
  }

  Employee Kyle{};
  Kyle.age = 36;

  Employee Frank {1, 32, 60000};

  std::cout << "Kyle's age is: " << Kyle.age << '\n';
  std::cout << Frank << '\n';

  Employee* ptr{ &Frank };
  std::cout << ptr->id << '\n'; // Better: use -> to select member from pointer to object

  Pair<int> p1{ 5, 6 };
  std::cout << max<int>(p1) << " is larger\n"; // explicit call to max<int>

  Pair<double> p2{ 1.2, 3.4 };
  std::cout << max(p2) << " is larger\n"; // call to max<double> using template argument deduction (prefer this)

  return 0;
}
} // namespace lesson13

namespace Feeling {
enum class Feeling {
  happy,
  tired,
  blue, // Feeling::blue doesn't collide with Color::blue
};
} // namespace Feeling