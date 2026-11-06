//
// Created by kyle on 11/5/26.
//

#include "lesson15.h"
#include <iostream>

namespace lesson15 {
class Simple
{
private:
  int m_id{};

public:
  Simple(int id)
      : m_id{ id }
  {
  }

  int getID() const { return m_id; }
  void setID(int id) { m_id = id; }

  void print() const { std::cout << m_id; }
};


#include <iostream>

  class Date
  {
  private:
    int m_year{};
    int m_month{};
    int m_day{};

  public:
    Date(int year, int month, int day); // constructor declaration

    void print() const; // print function declaration

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const  { return m_day; }
  };

  Date::Date(int year, int month, int day) // constructor definition
      : m_year{ year }
  , m_month{ month }
  , m_day{ day }
  {
  }

  void Date::print() const // print function definition
  {
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
  };

  int main()
  {
    const Date d{ 2015, 10, 14 };
    d.print();

    return 0;
  }


void runLesson() {
  Simple simple{1};
  simple.setID(2);

  simple.print();

}
} // lesson15