cmake_minimum_required(VERSION 3.15)
project(algorithm)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. DIRSRCS)

include_directories(./ ./sort ./linklist ./binarytree)
add_subdirectory(sort)
add_subdirectory(linklist)
add_subdirectory(binarytree)

add_executable(algorithm ${DIRSRCS})
target_link_libraries(algorithm binarytree linklist sort)
# add_executable(algorithm main.cpp sort/merge.h sort/excercise.h sort/heap.h sort/quick.h linklist/sort.h linklist/palindrome.h linklist/def.h linklist/reverse.h linklist/cycle.h linklist/intersection.h linklist/reorder.h linklist/partition.h linklist/copyComplexLinklist.h binarytree/commonParentNode.h binarytree/serialize.h binarytree/def.h)