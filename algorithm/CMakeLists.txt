cmake_minimum_required(VERSION 3.15)
project(algorithm)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. DIRSRCS)

include_directories(./ ./sort ./linklist ./binarytree ./string ./array)
add_subdirectory(sort)
add_subdirectory(linklist)
add_subdirectory(binarytree)
add_subdirectory(string)
add_subdirectory(array)

add_executable(algorithm ${DIRSRCS})
target_link_libraries(algorithm binarytree linklist sort array string)