cmake_minimum_required(VERSION 4.3)
project(Testing)

set(CMAKE_CXX_STANDARD 20)

add_executable(Testing main.cpp
        Constants/constants.h
        Constants/constants.h
        Random.h
        Lesson10/lesson10.cpp
        Lesson10/lesson10.h
        Lesson11/lesson11.cpp
        Lesson11/lesson11.h
        LessonCF/lessoncf.cpp
        LessonCF/lessoncf.h
        Lesson12/lesson12.cpp
        Lesson12/lesson12.h)
