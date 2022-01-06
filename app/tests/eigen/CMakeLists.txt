cmake_minimum_required(VERSION 3.14)

project(eigen.test)

set(VERSION 0.1)
set(DESCRIPTION "just a test")

add_executable(testit
	       main.cpp)

target_compile_features(testit PRIVATE cxx_std_17)
target_link_libraries(testit PRIVATE Eigen)
