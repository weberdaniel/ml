# Author: Daniel Weber
# About: This shall build dlib. There is only one way to build it.
#        pull it in with add_subdirectory(dlib) and it will automatically
#        create target dlib::dlib. This is recommended because it is only
#        way to enable debug mode.
cmake_minimum_required(VERSION 3.22)

project(external.mkl)

set(VERSION 0.1)
set(DESCRIPTION "MKL")

message("-- Creating Target MKL")

find_package(MKL CONFIG REQUIRED)

if(TARGET MKL) 
  set_target_properties(MKL PROPERTIES IMPORTED_GLOBAL TRUE)
  message("-- Creating Target MKL - done")
elseif()
  message(WARNING "-- Creating Target MKL - ERROR ")
endif()
