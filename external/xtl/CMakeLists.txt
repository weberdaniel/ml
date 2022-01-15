cmake_minimum_required(VERSION 3.22)

project(external.xtl)

set(VERSION 0.1)
set(DESCRIPTION "XTL")

include(ExternalProject)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

message("-- Creating Target XTL")

ExternalProject_Add(xtl URL ${CMAKE_CURRENT_LIST_DIR}/xtl
  CONFIGURE_COMMAND cmake -E echo "-- Skip config step."
  BUILD_COMMAND cmake -E echo "-- Skip build step."
  INSTALL_COMMAND cmake -E echo "-- Skip install step.")

ExternalProject_Get_Property(xtl source_dir)
ExternalProject_Get_Property(xtl binary_dir)

set(XTL_INCLUDE_DIRS ${source_dir}/include
	             ${binary_dir})

add_library(XTL INTERFACE IMPORTED GLOBAL)

target_include_directories(XTL INTERFACE ${XTL_INCLUDE_DIRS})

message("-- Creating Target XTL - done")
