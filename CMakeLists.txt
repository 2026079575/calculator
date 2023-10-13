cmake_minimum_required(VERSION 3.26)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(calculator)

add_executable(calculator
        calculator/calculator.h
        calculator/calculator.cpp
        calculator/calculatorMain.cpp2
)
