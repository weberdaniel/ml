cmake_minimum_required(VERSION 3.22)

project(external.blas)

include(ExternalProject)

set(VERSION 0.1)
set(DESCRIPTION "BLAS")

include(ExternalProject)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

message("-- Creating Target Blas")

find_package(BLAS REQUIRED)

if(BLAS_FOUND)
  message("-- Creating Target Blas - done")
  set_target_properties(BLAS::BLAS PROPERTIES IMPORTED_GLOBAL TRUE)
else()
  ExternalProject_Add(blas URL ${CMAKE_CURRENT_LIST_DIR}/blas
    INSTALL_COMMAND cmake -E echo "-- Skip install step." )
endif(BLAS_FOUND)

