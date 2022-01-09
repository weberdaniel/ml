cmake_minimum_required(VERSION 3.22)

project(external.plotcpp)

set(VERSION 0.1)
set(DESCRIPTION "new")

include(ExternalProject)

ExternalProject_Add(plotcpp URL ${CMAKE_CURRENT_LIST_DIR}/plotcpp
  INSTALL_COMMAND cmake -E echo "-- Skip install step."
  BUILD_COMMAND cmake -E echo "-- Skip build step."
  CONFIGURE_COMMAND cmake -E echo "-- Skip configure step.")

ExternalProject_Get_Property(plotcpp source_dir)

set(PLOTCPP_INC ${source_dir})

message("-- Creating target PLOTCPP")
add_library(PLOTCPP INTERFACE IMPORTED GLOBAL)

target_include_directories(PLOTCPP INTERFACE ${PLOTCPP_INC})
message("-- Creating target PLOTCPP - done")
