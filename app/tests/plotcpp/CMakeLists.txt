cmake_minimum_required(VERSION 3.22)

project(plotcpp.test)

set(VERSION 0.1)
set(DESCRIPTION "just a test")

add_executable(testplotcpp
	       main.cpp)

target_compile_features(testplotcpp PRIVATE cxx_std_17)
target_link_libraries(testplotcpp PRIVATE PLOTCPP)
