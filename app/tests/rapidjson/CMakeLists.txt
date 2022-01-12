cmake_minimum_required(VERSION 3.22)

project(rapidjson.test)

set(VERSION 0.1)
set(DESCRIPTION "rapid json")

add_executable(testrapidjson
	       main.cpp)

target_compile_features(testrapidjson PRIVATE cxx_std_17)
target_link_libraries(testrapidjson PRIVATE RapidJson)
