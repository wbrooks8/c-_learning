//
// Created by mymus on 11/7/2026.
//

#include "lesson16.h"

#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

namespace lesson16 {

// For range-based for loops, prefer to define the element type as:
//
// auto when you want to modify copies of the elements.
// auto& when you want to modify the original elements.
// const auto& otherwise (when you just need to view the original elements).

template <typename T> void passByRef(const std::vector<T> &arr) {
  std::cout << arr[0] << '\n';
}

void passByRefAuto(const auto &arr) // abbreviated function template
{
  std::cout << arr[0] << '\n';
}

// index needs to be an int, not a std::size_t, otherwise we won't be able to
// detect if the user passes in a negative index
template <typename T> void printElement(const std::vector<T> &arr, int index) {
  if (index < 0 ||
      index >=
          static_cast<int>(arr.size())) // In C++20, could use std::ssize(arr)
                                        // to avoid the cast
    std::cout << "Invalid index\n";
  else
    std::cout << "The element has value "
              << arr[static_cast<std::size_t>(index)] << '\n';
}

// To initialize a vector inside a class:
struct Foo {
  std::vector<int> v{std::vector<int>(8)}; // ok
};

template <typename T> void printArray(const std::vector<T> &arr) {
  for (std::size_t index{0}; index < arr.size(); ++index) {
    std::cout << arr[index] << ' ';
  }

  if (arr.size() > 0)
    std::cout << '\n';
}

template <typename T> int findIndex(const std::vector<T> &arr, T val) {
  for (std::size_t index{0}; index < arr.size(); ++index) {
    if (arr[index] == val)
      return static_cast<int>(index);
  }

  return -1; // -1 is not a valid index, so we can use it as an error return
             // value
}

int getValidNumber() {
  // First, read in valid input from user
  int num{};
  do {
    std::cout << "Enter a number between 1 and 9: ";
    std::cin >> num;

    // if the user entered an invalid character
    if (!std::cin)
      std::cin.clear(); // reset any error flags

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // ignore any extra characters in the input buffer
                           // (regardless of whether we had an error or not)

  } while (num < 1 || num > 9);

  return num;
}

template <typename T>
bool isValueInArray(const std::vector<T> &arr, const T &value) {
  // we'll use a reference since we don't know if T is expensive to copy
  for (const auto &a : arr) {
    if (a == value)
      return true;
  }

  return false;
}

namespace Students {
enum Names {
  kenny,   // 0
  kyle,    // 1
  stan,    // 2
  butters, // 3
  cartman, // 4
  wendy,   // 5 (added)
  // add future enumerators here
  max_students // now 6
};
}

namespace Animals {
enum Animals { chicken, dog, cat, elephant, duck, snake, max_animals };

const std::vector legs{2, 4, 4, 4, 2, 0};
} // namespace Animals

void printCapLen(const std::vector<int> &v) {
  std::cout << "Capacity: " << v.capacity() << " Length:" << v.size() << '\n';
}

void printStack(const std::vector<int> &stack) {
  if (stack.empty()) // if stack.size == 0
    std::cout << "Empty";

  for (auto element : stack)
    std::cout << element << ' ';

  // \t is a tab character, to help align the text
  std::cout << "\tCapacity: " << stack.capacity() << "  Length " << stack.size()
            << "\n";
}

void runLesson() {
  // Defined using CTAD
  std::vector squares{1, 4, 9, 16, 25};

  std::vector<int> sampleV{};
  std::vector<int> primes{2, 3, 5, 7};
  std::vector<int> data(
      10); // vector containing 10 int elements, value-initialized to 0

  std::vector<int> arr(3); // create a vector of length 3

  // std::cout << "Enter 3 integers: ";
  // std::cin >> arr[0] >> arr[1] >> arr[2];

  std::cout << "The sum is: " << arr[0] + arr[1] + arr[2] << '\n';
  std::cout << "The product is: " << arr[0] * arr[1] * arr[2] << '\n';

  std::vector<char> hello{'h', 'e', 'l', 'l', 'o'};

  std::cout << hello.size() << '\n';
  std::cout << hello[1] << hello.at(1) << '\n';

  passByRef(primes);
  passByRef(hello);

  std::vector<std::string_view> names{"Alex",  "Betty", "Caroline", "Dave",
                                      "Emily", "Fred",  "Greg",     "Holly"};

  std::cout << "Enter a name: ";
  std::string username{};
  std::cin >> username;

  // By explicitly specifying std::string_view as a function template argument,
  // the compiler will implicitly convert username to `std::string_view` to
  // match the parameter type.
  bool found{isValueInArray<std::string_view>(names, username)};

  // The following is also okay.  If we rely on template argument deduction
  // instead, the compiler won't do implicit conversions, so we need to make
  // sure `username` has the expected type. bool found{ isValueInArray(names,
  // static_cast<std::string_view>(username)) };

  if (found)
    std::cout << username << " was found.\n";
  else
    std::cout << username << " was not found.\n";

  std::vector<int> testScores(
      Students::max_students); // will now allocate 6 elements

  testScores[Students::stan] = 76; // still works

  std::cout << "The class has " << Students::max_students << " students\n";

  assert(std::size(testScores) == Students::max_students);

  // Ensure the number of legs is the same as the number of animals
  assert(std::size(Animals::legs) == Animals::max_animals);

  std::cout << "An elephant has " << Animals::legs[Animals::elephant]
            << " legs.\n";

  std::vector v{0, 1, 2}; // create vector with 3 elements
  std::cout << "The length is: " << v.size() << '\n';

  v.resize(5); // resize to 5 elements
  std::cout << "The length is: " << v.size() << '\n';

  std::vector<int> a(1000); // allocate room for 1000 elements
  printCapLen(a);

  a.resize(0); // resize to 0 elements
  printCapLen(a);

  a.shrink_to_fit();
  printCapLen(a);

  std::vector<int> stack{};

  printStack(stack);

  stack.reserve(6); // reserve space for 6 elements (but do not change length)
  printStack(stack);

  stack.push_back(1);
  printStack(stack);

  stack.push_back(2);
  printStack(stack);

  stack.push_back(3);
  printStack(stack);

  std::cout << "Top: " << stack.back() << '\n';

  stack.pop_back();
  printStack(stack);

  stack.pop_back();
  printStack(stack);

  stack.pop_back();
  printStack(stack);
}

void endOfChapter() {
  std::vector evens{2, 4, 6, 8, 10, 12};
  const std::vector decimals{1.2, 3.4, 5.6, 7.8};
  using namespace std::literals::string_view_literals; // for sv suffix
  const std::vector names{
      "Alex"sv, "Brad"sv, "Charles"sv,
      "Dave"sv}; // sv suffix needed for CTAD to infer std::string_view
  std::vector single{12};
  std::vector<int> twelve(12);
}

namespace Items {
enum Type { health_potion, torch, arrow, max_items };
}

std::string_view getItemNamePlural(Items::Type type)
{
  switch (type)
  {
  case Items::health_potion:  return "health potions";
  case Items::torch:          return "torches";
  case Items::arrow:          return "arrows";

  default:                    return "???";
  }
}

std::string_view getItemNameSingular(Items::Type type)
{
  switch (type)
  {
  case Items::health_potion:  return "health potion";
  case Items::torch:          return "torch";
  case Items::arrow:          return "arrow";

  default:                    return "???";
  }
}

// Helper function to convert `value` into an object of type std::size_t
// UZ is the suffix for literals of type std::size_t.
template <typename T>
constexpr std::size_t toUZ(T value)
{
  // make sure T is an integral type
  static_assert(std::is_integral<T>() || std::is_enum<T>());

  return static_cast<std::size_t>(value);
}


void printInventoryItem(const std::vector<int>& inventory, Items::Type type)
{
  bool plural { inventory[toUZ(type)] != 1 };
  std::cout << "You have " << inventory[toUZ(type)] << ' ';
  std::cout << (plural ? getItemNamePlural(type) : getItemNameSingular(type)) << '\n';
}

// Inventory items should have integral quantities, so we don't need a function template here
int countTotalItems(const std::vector<int>& inventory)
{
  int sum { 0 };
  for (auto e: inventory)
    sum += e;
  return sum;
}

template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(const std::vector<T>& v)
{
  // Assume element 0 is the minimum and the maximum
  std::size_t minIndex { 0 };
  std::size_t maxIndex { 0 };

  // Look through the remaining elements to see if we can find a smaller or larger element
  for (std::size_t index { 1 }; index < v.size(); ++index)
  {
    if (v[index] < v[minIndex])
      minIndex = index;
    if (v[index] > v[maxIndex])
      maxIndex = index;
  }

  return { minIndex, maxIndex };
}

template <typename T>
void printArray2(const std::vector<T>& v)
{
  bool comma { false };
  std::cout << "With array ( ";
  for (const auto& e: v)
  {
    if (comma)
      std::cout << ", ";

    std::cout << e;
    comma = true;
  }
  std::cout << " ):\n";
}

void main() {
  std::vector inventory { 1, 5, 10 };
  assert(std::size(inventory) == Items::max_items); // make sure our inventory has the correct number of initializers

  // Since we can't iterate over an enumerated type using a ranged-for, we'll need to use a traditional for-loop here
  for (int i=0; i < Items::max_items; ++i)
  {
    auto item { static_cast<Items::Type>(i) };
    printInventoryItem(inventory, item);
  }

  std::cout << "You have " << countTotalItems(inventory) << " total items\n";

  std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
  printArray2(v1);

  auto m1 { findMinMaxIndices(v1) };
  std::cout << "The min element has index " << m1.first << " and value " << v1[m1.first] << '\n';
  std::cout << "The max element has index " << m1.second << " and value " << v1[m1.second] << '\n';

  std::cout << '\n';

  std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
  printArray2(v2);

  auto m2 { findMinMaxIndices(v2) };
  std::cout << "The min element has index " << m2.first << " and value " << v2[m2.first] << '\n';
  std::cout << "The max element has index " << m2.second << " and value " << v2[m2.second] << '\n';
}


} // namespace lesson16
