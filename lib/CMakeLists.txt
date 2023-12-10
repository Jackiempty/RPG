cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 17)

aux_source_directory(. DIR_LIB_SRCS)
add_library (rpg_lib ${DIR_LIB_SRCS})