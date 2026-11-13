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
        Lesson15/lesson15.cpp
        Constants/constants.h
        Random.h
        Lesson15/Date.cpp
        Lesson15/Date.h
        Lesson16/lesson16.cpp
        Lesson16/lesson16.h
        Lesson17/lesson17.cpp
        Lesson17/lesson17.h
        Lesson17/fantasyStore.cpp
        Lesson17/fantasyStore.h
        Lesson18/lesson18.cpp
        Lesson18/lesson18.h
        Timer.h
)

# Set include directories for headers
target_include_directories(Testing PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Lesson10
        ${CMAKE_CURRENT_SOURCE_DIR}/Lesson11
        ${CMAKE_CURRENT_SOURCE_DIR}/LessonCF
        ${CMAKE_CURRENT_SOURCE_DIR}/Lesson12
        ${CMAKE_CURRENT_SOURCE_DIR}/Lesson13
        ${CMAKE_CURRENT_SOURCE_DIR}/Lesson14
        ${CMAKE_CURRENT_SOURCE_DIR}/Lesson15
        ${CMAKE_CURRENT_SOURCE_DIR}/Constants
)

# Ensure C++ standard library linking
target_link_libraries(Testing PRIVATE stdc++)