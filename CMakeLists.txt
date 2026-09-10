cmake_minimum_required(VERSION 4.0)
project(First_laba)

set(CMAKE_CXX_STANDARD 20)

add_executable(First_laba main.cpp
        Transporter.h
        Transporter.cpp
        Car.cpp
        Car.h
        Train.cpp
        Train.h
        Plane.cpp
        Plane.h
        Keeper.cpp
        Keeper.h
)
