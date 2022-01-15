cmake_minimum_required(VERSION 3.22)

project(xtensorblas.test)

set(VERSION 0.1)
set(DESCRIPTION "just a test")

add_executable(xtensorblastest main.cpp)

#get_target_property(TORCH_INCLUDE_DIR torch INCLUDE_DIRECTORIES)

target_compile_features(xtensorblastest PRIVATE cxx_std_17)
target_link_libraries(xtensorblastest PRIVATE XTENSORBLAS XTENSOR XTL BLAS::BLAS)
#target_include_directories(testtorch PRIVATE ${TORCH_INCLUDE_DIRECTORIES})
