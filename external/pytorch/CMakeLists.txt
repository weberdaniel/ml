cmake_minimum_required(VERSION 3.22)

project(external.torch)

message("-- Creating target Torch")
set(Torch_DIR "/home/daniel/libtorch/share/cmake/Torch/")
find_package(Torch REQUIRED)
set_target_properties(torch PROPERTIES IMPORTED_GLOBAL TRUE)
set_target_properties(torch_cpu PROPERTIES IMPORTED_GLOBAL TRUE)
message("-- Includes: ${TORCH_INCLUDE_DIRS}")
message("-- Creating target Torch - done")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

#add_library(Torch INTERFACE IMPORTED GLOBAL)
#target_link_libraries(Torch INTERFACE "${TORCH_LIBRARIES}")
#target_include_directories(Torch INTERFACE "${TORCH_INCLUDE_DIR}")
#target_compile_features(Torch INTERFACE cxx_std_17)

# The following code block is suggested to be used on Windows.
# According to https://github.com/pytorch/pytorch/issues/25457,
# the DLLs need to be copied to avoid memory errors.
#if (MSVC)
#  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
#  add_custom_command(TARGET example-app
#                     POST_BUILD
#                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#                     ${TORCH_DLLS}
#                     $<TARGET_FILE_DIR:example-app>)
#endif (MSVC)
