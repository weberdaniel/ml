cmake_minimum_required(VERSION 3.14)

project(dlib.test)

set(VERSION 0.1)
set(DESCRIPTION "just a test")

add_executable(testdlib
	       main.cpp)

target_compile_features(testdlib PRIVATE cxx_std_17)
target_link_libraries(testdlib PRIVATE dlib::dlib)
