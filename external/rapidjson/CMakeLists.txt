cmake_minimum_required(VERSION 3.22)

project(external.rapidjson)

set(VERSION 0.18.5)
set(DESCRIPTION "RapidJson")


# add all local cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

include(ExternalProject)

message("-- Creating Target RapidJson - use remote repository")
ExternalProject_Add(rapid URL ${CMAKE_CURRENT_LIST_DIR}/rapidjson
  INSTALL_COMMAND cmake -E echo "-- Skip install step.")

ExternalProject_Get_Property(rapid source_dir)
ExternalProject_Get_Property(rapid binary_dir)

file(MAKE_DIRECTORY ${binary_dir}/include)
file(MAKE_DIRECTORY ${source_dir}/include)

set(RAPIDJSON_INCLUDE_DIRS ${binary_dir}/include ${source_dir}/include)
message("-- Creating Target RapidJson - Include Dir ${RAPIDJSON_INCLUDE_DIRS}")

add_library(RapidJson INTERFACE IMPORTED GLOBAL)
target_include_directories(RapidJson INTERFACE ${RAPIDJSON_INCLUDE_DIRS})

message("-- Creating Target RapidJson - done")
