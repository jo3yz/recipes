cmake_minimum_required(VERSION 3.15)
include_directories(. )
aux_source_directory(. DIR_SORT_SRCS)
add_library(sort ${DIR_SORT_SRCS})