cmake_minimum_required(VERSION 3.22)

project(external.cppcsv)

set(VERSION 0.1)
set(DESCRIPTION "new")

include(ExternalProject)

ExternalProject_Add(cppcsv URL ${CMAKE_CURRENT_LIST_DIR}/fast-cpp-csv-parser
  INSTALL_COMMAND cmake -E echo "-- Skip install step."
  BUILD_COMMAND cmake -E echo "-- Skip build step."
  CONFIGURE_COMMAND cmake -E echo "-- Skip configure step.")

ExternalProject_Get_Property(cppcsv source_dir)

set(CPPCSV_INC ${source_dir})

message("-- Creating target CPPCSV")
add_library(CPPCSV INTERFACE IMPORTED GLOBAL)

target_include_directories(CPPCSV INTERFACE ${CPPCSV_INC})
message("-- Creating target CPPCSV - done")
