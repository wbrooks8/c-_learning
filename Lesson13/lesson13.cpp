//
// Created by kyle on 11/2/26.
//

#include <cstdint>

#include "lesson13.h"

namespace lesson13 {
    // Define a new unscoped enumeration named Color
    // Use an 8-bit integer as the enum underlying type
    enum Color2 : std::int8_t
    {
        // Here are the enumerators
        // These symbolic constants define all the possible values this type can hold
        // Each enumerator is separated by a comma, not a semicolon
        red,
        green,
        blue, // trailing comma optional but recommended
    }; // the enum definition must end with a semicolon

    int runLesson()
    {
        // Define a few variables of enumerated type Color
        Color apple { red };   // my apple is red
        Color shirt { green }; // my shirt is green
        Color cup { blue };    // my cup is blue

        Color socks { white }; // error: white is not an enumerator of Color
        Color hat { 2 };       // error: 2 is not an enumerator of Color

        return 0;
    }
}

namespace Feeling
{
    enum Feeling
    {
        happy,
        tired,
        blue, // Feeling::blue doesn't collide with Color::blue
    };
}// lesson13