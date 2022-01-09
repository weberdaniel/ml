cmake_minimum_required(VERSION 3.22)

project(mlpack.test)

set(VERSION 0.1)
set(DESCRIPTION "just a test")

add_executable(testmlpack
	       main.cpp)

target_compile_features(testmlpack PRIVATE cxx_std_17)
target_link_libraries(testmlpack PRIVATE MLPACK)
