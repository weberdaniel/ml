cmake_minimum_required(VERSION 3.22)
project(external.shogun)

set(VERSION 0.1)
set(DESCRIPTION "shogun")

include(ExternalProject)

ExternalProject_Add(shogun URL ${CMAKE_CURRENT_LIST_DIR}/shogun
  CMAKE_ARGS -DBUILD_META_EXAMPLES=Off
  INSTALL_COMMAND cmake -E echo "--Skip install step")

ExternalProject_Get_Property(shogun source_dir)
ExternalProject_Get_Property(shogun binary_dir)

set(SHOGUN_INC ${source_dir}/include
	       ${binary_dir}/include)

message("-- Creating Target SHOGUN")
message("-- Include: ${SHOGUN_INC}")
add_library(SHOGUN INTERFACE IMPORTED GLOBAL)
target_include_directories(SHOGUN INTERFACE ${SHOGUN_INC})
message("-- Target SHOGUN - done")
