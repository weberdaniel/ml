# initialize the project
cmake_minimum_required(VERSION 3.16)

project(ML
        VERSION 0.1
	DESCRIPTION "A machine learning project")

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
  option(GIT_SUBMODULE "Check submodules during build" ON)
  if(GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}.")
    endif()
  endif()
endif()

set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(external)
add_subdirectory(doc)
add_subdirectory(app)
