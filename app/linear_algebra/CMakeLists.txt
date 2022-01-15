cmake_minimum_required(VERSION 3.22)

project(eigen.test)

set(VERSION 0.1)
set(DESCRIPTION "just a test")

add_executable(linalg
	       main.cpp)

target_compile_features(linalg PRIVATE cxx_std_17)
target_link_libraries(linalg PRIVATE Eigen3::Eigen)
