cmake_minimum_required(VERSION 3.15)
include_directories(. )
aux_source_directory(. DIR_BINARYTREE_SRCS)
add_library(binarytree ${DIR_BINARYTREE_SRCS})