cmake_minimum_required(VERSION 3.22)

project(external.mlpack)

set(VERSION 0.1)
set(DESCRIPTION "MLPack")

include(ExternalProject)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

message("-- Creating Target MLPACK")

find_package(MLPACK REQUIRED)

if(MLPACK_FOUND)
  message("-- Creating Target MLPACK - use local install")
  add_library(MLPACK INTERFACE IMPORTED GLOBAL)
  target_include_directories(MLPACK INTERFACE ${MLPACK_INCLUDE_DIRS})
  target_link_libraries(MLPACK INTERFACE ${MLPACK_LIBRARIES})
elseif()
  message("-- Creating Target MLPACK - use remote repository")
  ExternalProject_Add(mlpack URL ${CMAKE_CURRENT_LIST_DIR}/mlpack
  DEPENDS Armadillo
  #CMAKE_ARGS -D
  INSTALL_COMMAND cmake -E echo "-- Skip install step.")
endif()
