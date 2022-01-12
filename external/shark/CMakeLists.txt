cmake_minimum_required(VERSION 3.22)
project(external.sharkml)

set(VERSION 0.1)
set(DESCRIPTION "new")

include(ExternalProject)

ExternalProject_Add(sharkml URL ${CMAKE_CURRENT_LIST_DIR}/shark
  INSTALL_COMMAND cmake -E echo "--Skip install step")

ExternalProject_Get_Property(sharkml source_dir)
ExternalProject_Get_Property(sharkml binary_dir)

set(SHARK_INC ${source_dir}/include
	      ${binary_dir}/include)

message("-- Creating Target SHARKML")
message("-- Include: ${SHARK_INC}")
add_library(SHARKML INTERFACE IMPORTED GLOBAL)
target_include_directories(SHARKML INTERFACE ${SHARK_INC})
message("-- Target SHARKML - done")

