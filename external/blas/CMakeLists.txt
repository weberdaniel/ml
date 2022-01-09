# Author: Daniel Weber
# About: This sets up the BLAS library. It is possible to install it via a package
#        libblas-dev and pull it in via find_package. Also it is possible to download
#        it and build it from scratch.
# TODO: only download BLAS codebase if local not found

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
  set_target_properties(BLAS::BLAS PROPERTIES IMPORTED_GLOBAL TRUE)
  message("-- Creating Target Blas - done")
else()
  ExternalProject_Add(blas URL ${CMAKE_CURRENT_LIST_DIR}/OpenBLAS
    INSTALL_COMMAND cmake -E echo "-- Skip install step." )
  ExternalProject_Get_Property(blas source_dir)
  ExternalProject_Get_Property(blas binary_dir)

  set(BLAS_LIBS ${source_dir}/libopenblas.so)
  set(BLAS_INC ${source_dir})
  add_library(BLAS::BLAS INTERFACE IMPORTED GLOBAL)
  target_include_directories(BLAS::BLAS INTERFACE ${BLAS_INC})
  target_link_libraries(BLAS::BLAS INTERFACE ${BLAS_LIBS})
  target_compile_features(BLAS::BLAS INTERFACE cxx_std_17)
  message("-- Creating Target Blas - done")
endif()
