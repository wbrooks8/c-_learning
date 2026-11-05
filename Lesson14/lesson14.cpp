//
// Created by kyle on 11/4/26.
//

// Include the header file for this lesson
#include "lesson14.h"

#include <iostream>

namespace lesson14 {
    // Date class - demonstrates encapsulation with private member variables
    // Member variables are prefixed with 'm_' to distinguish them from parameters
    class Date // we changed struct to class
    {
    public:        // and added this line, which is called an access specifier
      int m_day{}; // and added "m_" prefixes to each of the member names
      int m_month{};
      int m_year{};
    };

    // Employee class - demonstrates basic class structure with constructor and methods
    class Employee {
      std::string m_name{};  // Member variable storing employee name

    public:
      // Constructor that initializes the employee name
      Employee(const std::string &name) : m_name{name} {
        std::cout << "Employee() constructor called" << std::endl;
      };

      // Setter method to update employee name
      void setName(std::string_view name) { m_name = name; }

      // Getter method that returns the employee name by const reference for efficiency
      const std::string &getName() const {
        return m_name;
      } //  getter returns by const reference. Type should match returned object.
    };

    // Function to print date in format dd/mm/yyyy
    void printDate(const Date &date) {
      std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
    }

    // Ball class - demonstrates constructor initialization and encapsulation
    class Ball {
      std::string m_color;  // Member variable for ball color
      double m_radius{};    // Member variable for ball radius, initialized to 0.0

    public:
      // Constructor that initializes both member variables using member initializer list
      Ball(const std::string &color, const double &radius)
          : m_color{color}, m_radius{radius} {}

      // Method to print the ball's color
      void printBall() {
        std::cout << "The color of the ball is: " << m_color << std::endl;
      }

      // Getter methods for accessing private member variables
      const std::string &getColor() const { return m_color; }
      double getRadius() const { return m_radius; }
    };

    // Function to print ball information in a formatted way
    void print(const Ball &ball) {
      std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
    }

    // Point2d class - demonstrates constructor overloading and default constructor
    class Point2d {
    private:
      double m_x{0.0};  // X coordinate, initialized to 0.0
      double m_y{0.0};  // Y coordinate, initialized to 0.0

    public:
      // Default constructor - creates a point at origin (0,0)
      Point2d() = default;

      // Parameterized constructor - creates a point with specified coordinates
      Point2d(double x, double y) : m_x{x}, m_y{y} {}

      // Method to print point coordinates in formatted output
      void print() const{
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
      }
    };

    // Main function demonstrating usage of the classes defined above
    int runLesson() {
      // Create a Date object with day=4, month=10, year=21
      Date date{4, 10, 21};
      printDate(date);

      // Create Employee object named "Joe" - constructor called automatically
      Employee Joe{"Joe"}; // joe exists until end of function
      Joe.setName("Joe");

      // Print employee name using getter method
      std::cout << Joe.getName() << std::endl; // returns joe.m_name by reference

      // Create two Ball objects with different colors and radii
      Ball blue{"blue", 10.0};
      print(blue);

      Ball red{"red", 12.0};
      print(red);

      // Create Point2d objects - first default constructor, second with parameters
      Point2d first{};  // Creates point at origin (0,0)
      Point2d second{ 3.0, 4.0 };  // Creates point at (3.0, 4.0)

      // The following line would cause a compilation error because there's no matching constructor
      // Point2d third{ 4.0 }; // should error if uncommented

      // Print the coordinates of the points
      first.print();
      second.print();
      // third.print();  // This would be an error if uncommented

      return 0;
    }
} // namespace lesson14