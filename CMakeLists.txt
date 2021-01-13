cmake_minimum_required(VERSION 3.17)
project(DS_C_ C)

set(CMAKE_C_STANDARD 99)

add_executable(PrintN algorithm/PrintN.c)
add_executable(main main.c)
add_executable(polynomial algorithm/polynomial.c)