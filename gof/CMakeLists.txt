cmake_minimum_required(VERSION 3.15)
project(GOF)

set(CMAKE_CXX_STANDARD 11)

add_executable(GOF main.cpp create/factory.cpp create/factory.h)