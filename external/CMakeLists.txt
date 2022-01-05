cmake_minimum_required(VERSION 3.14)

project(external.eigen)

set(VERSION )
set(DESCRIPTION "math lib")

include(ExternalProject)

#add all local cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

message("-- Creating Target Eigen")
#add Eigen target
ExternalProject_Add(eigen URL ${CMAKE_CURRENT_LIST_DIR}/eigen
  INSTALL_COMMAND cmake -E echo "-- Skip install step.")
ExternalProject_Get_Property(eigen source_dir)
ExternalProject_Get_Property(eigen binary_dir)
# Create dirs of the external project
file(MAKE_DIRECTORY ${source_dir})

set(EIGEN_INCLUDE_DIRS ${source_dir})

add_library(Eigen INTERFACE IMPORTED GLOBAL)
# set the include paths
target_include_directories(Eigen INTERFACE ${EIGEN_INCLUDE_DIRS})
target_compile_features(Eigen INTERFACE cxx_std_17)
message("-- Creating Target Eigen -- done")
	               
