cmake_minimum_required(VERSION 3.10)
project(Testing)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable with all source files
add_executable(Testing
        main.cpp
        Lesson10/lesson10.cpp
        Lesson11/lesson11.cpp
        LessonCF/lessoncf.cpp
        Lesson12/lesson12.cpp
        Lesson13/lesson13.cpp
        Lesson14/lesson14.cpp
        Constants/constants.h
        Random.h
)