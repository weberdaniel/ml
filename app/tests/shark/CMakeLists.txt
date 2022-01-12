cmake_minimum_required(VERSION 3.22)

project(app.test.shark)

set(VERSION 0.1)
set(DESCRIPTION "shark ml")

add_executable(testshark main.cpp)

target_compile_features(testshark PRIVATE cxx_std_17)
target_link_libraries(testshark PRIVATE SHARKML)
