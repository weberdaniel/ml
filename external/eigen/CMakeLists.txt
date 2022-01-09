# Author: Daniel Weber
# About: This provides Eigen library. Two ways: Eitehr from
#        scratch or pull in package libeigen3-dev via
#        find_package.
cmake_minimum_required(VERSION 3.22)

#create a project for the eigen library
project(external.eigen)

set(VERSION 0.18.5)
set(DESCRIPTION "Eigen")

include(ExternalProject)

# add all local cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

#TODO: check wether EIgen library is already installed on the
#      system

message("-- Creating Target Eigen")

find_package(Eigen3 REQUIRED)

# use the ExternalProject_Add to add the corresponding git
# submodule. In this case we have a header-only-library. 

ExternalProject_Add(eigen URL ${CMAKE_CURRENT_LIST_DIR}/eigen
  INSTALL_COMMAND cmake -E echo "-- Skip install step.")

# All of the code will be put into the build folder, from
# where headers can be included for the build. Retrieve
# the location of the build binary and build source directory

ExternalProject_Get_Property(eigen source_dir)
ExternalProject_Get_Property(eigen binary_dir)

# add those directories to the INCLUDE path of this library

set(EIGEN_INCLUDE_DIRS ${binary_dir}
	               ${source_dir})

# create a new CMake Target which will be imported into the
# global Cmake namespace to make it accessible from the outside
# of this project.

add_library(Eigen INTERFACE IMPORTED GLOBAL)

# add the include directorys

target_include_directories(Eigen INTERFACE ${EIGEN_INCLUDE_DIRS})

# we are done already since there are no binaries

message("-- Creating Target Eigen - done")
