cmake_minimum_required(VERSION 3.15)
include_directories(. )
aux_source_directory(. DIR_LINKLIST_SRCS)
add_library(linklist ${DIR_LINKLIST_SRCS})