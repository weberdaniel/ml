cmake_minimum_required(VERSION 3.14)

project(external.caf)

set(VERSION 0.18.5)
set(DESCRIPTION "Eigen")

include(ExternalProject)

# add all local cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

message("-- Creating Target Eigen")
