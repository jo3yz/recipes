cmake_minimum_required(VERSION 3.15)
include_directories(. )
aux_source_directory(. DIR_STRING_SRCS)
add_library(string ${DIR_STRING_SRCS})