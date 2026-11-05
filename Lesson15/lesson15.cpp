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

void runLesson() {
  Simple simple{1};
  simple.setID(2);

  simple.print();

}
} // lesson15