cmake_minimum_required(VERSION 3.22)

project(external.xtensor-blas)

set(VERSION 0.1)
set(DESCRIPTION "Xtensor-BLAS")

include(ExternalProject)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

message("-- Creating Target XTENSORBLAS")

ExternalProject_Add(xtensorblas URL ${CMAKE_CURRENT_LIST_DIR}/xtensor-blas
  CONFIGURE_COMMAND cmake -E echo "-- Skip config step."
  BUILD_COMMAND cmake -E echo "-- Skip build step."
  INSTALL_COMMAND cmake -E echo "-- Skip install step.")

ExternalProject_Get_Property(xtensorblas source_dir)
ExternalProject_Get_Property(xtensorblas binary_dir)

set(XTENSORBLAS_INCLUDE_DIRS ${source_dir}/include
	                     ${binary_dir})

add_library(XTENSORBLAS INTERFACE IMPORTED GLOBAL)

target_include_directories(XTENSORBLAS INTERFACE ${XTENSORBLAS_INCLUDE_DIRS})

message("-- Creating Target XTENSORBLAS - done")
