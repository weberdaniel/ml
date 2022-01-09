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
  message("-- Creating Target MLPACK - try use remote repository...")
  message(FATAL_ERROR "-- Creating Target MLPACK - ... not possible because of complex build")
  #ExternalProject_Add(mlpack URL ${CMAKE_CURRENT_LIST_DIR}/mlpack
  #DEPENDS Armadillo
  #CMAKE_ARGS -DARMADILLO_LIBRARY=${ARMA_LIB} -DARMADILLO_INCLUDE_DIR=${ARMA_INC} -DUSE_OPENMP=OFF
  #INSTALL_COMMAND cmake -E echo "-- Skip install step.")
  #ExternalProject_Get_Property(mlpack source_dir)
  #ExternalProject_Get_Property(mlpack binary_dir)
  #set(MLPACK_INCLUDE_DIRS ${source_dir})
  #set(MLPACK_LIBRARIES ${source_dir}
  #  ${binary_dir})
	       #add_library(MLPACK INTERFACE IMPORTED GLOBAL)
	       #target_include_directories(MLPACK INTERFACE ${MLPACK_INCLUDE_DIRS})
	       #target_link_libraries(MLPACK INTERFACE ${MLPACK_LIBRARIES})
endif()
