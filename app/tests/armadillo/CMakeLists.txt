cmake_minimum_required(VERSION 3.22)

project(armadillo.test)

set(VERSION 0.1)
set(DESCRIPTION "just a test")

add_executable(testarmadillo
	       main.cpp)

target_compile_features(testit PRIVATE cxx_std_17)
target_link_libraries(testarmadillo PRIVATE Armadillo BLAS::BLAS)
