cmake_minimum_required(VERSION 3.14)

project(external.caf)

set(VERSION 0.18.5)
set(DESCRIPTION "Eigen")

include(ExternalProject)

# add all local cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

message("-- Creating Target Eigen")
ExternalProject_Add(eigen URL ${CMAKE_CURRENT_LIST_DIR}/eigen
  INSTALL_COMMAND cmake -E echo "-- Skip install step.")
ExternalProject_Get_Property(eigen source_dir)
ExternalProject_Get_Property(eigen binary_dir)

set(EIGEN_INCLUDE_DIRS ${binary_dir}
	               ${source_dir})

add_library(Eigen INTERFACE IMPORTED GLOBAL)
target_include_directories(Eigen INTERFACE ${EIGEN_INCLUDE_DIRS})
message("-- Creating Target Eigen - done")
