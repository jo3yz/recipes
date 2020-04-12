cmake_minimum_required(VERSION 3.15)
include_directories(. )
aux_source_directory(. DIR_ARRAY_SRCS)
add_library(array ${DIR_ARRAY_SRCS})