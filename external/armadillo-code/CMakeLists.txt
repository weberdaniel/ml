cmake_minimum_required(VERSION 3.22)

project(external.armadillo)

set(VERSION 0.1)
set(DESCRIPTION "Armadillo")

include(ExternalProject)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

message("-- Creating Target Armadillo")

ExternalProject_Add(armadillo URL ${CMAKE_CURRENT_LIST_DIR}/armadillo-code
  INSTALL_COMMAND cmake -E echo "-- Skip install step.")

ExternalProject_Get_Property(armadillo source_dir)
ExternalProject_Get_Property(armadillo binary_dir)
file(MAKE_DIRECTORY ${source_dir}/include)
set(ARMADILLO_INCLUDE_DIRS ${source_dir}/include)
set(ARMADILLO_LIBS ${binary_dir}/libarmadillo.so
                   ${binary_dir}/libarmadillo.so.10
                   ${binary_dir}/libarmadillo.so.10.8.0)

add_library(Armadillo INTERFACE IMPORTED GLOBAL)
target_include_directories(Armadillo INTERFACE ${ARMADILLO_INCLUDE_DIRS})
target_link_libraries(Armadillo INTERFACE ${ARMADILLO_LIBS})

message("-- Creating Target Armadillo - done")
