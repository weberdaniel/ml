cmake_minimum_required(VERSION 3.22)

project(external.xtensor)

set(VERSION 0.1)
set(DESCRIPTION "Xtensor")

include(ExternalProject)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

message("-- Creating Target XTENSOR")

ExternalProject_Add(xtensor URL ${CMAKE_CURRENT_LIST_DIR}/xtensor
  CONFIGURE_COMMAND cmake -E echo "-- Skip config step."
  BUILD_COMMAND cmake -E echo "-- Skip build step."
  INSTALL_COMMAND cmake -E echo "-- Skip install step.")

ExternalProject_Get_Property(xtensor source_dir)
ExternalProject_Get_Property(xtensor binary_dir)

set(XTENSOR_INCLUDE_DIRS ${source_dir}/include
	                 ${binary_dir})

add_library(XTENSOR INTERFACE IMPORTED GLOBAL)

target_include_directories(XTENSOR INTERFACE ${XTENSOR_INCLUDE_DIRS})

message("-- Creating Target XTENSOR - done")
