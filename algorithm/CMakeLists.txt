cmake_minimum_required(VERSION 3.15)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)
include_directories(sort)
add_executable(algorithm main.cpp sort/merge.h sort/excercise.h sort/heap.h sort/quick.h linklist/sort.h linklist/palindrome.h linklist/def.h linklist/reverse.h linklist/cycle.h linklist/intersection.h linklist/reorder.h linklist/partition.h linklist/copyComplexLinklist.h)