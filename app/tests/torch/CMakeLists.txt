cmake_minimum_required(VERSION 3.22)

project(torch.test)

set(VERSION 0.1)
set(DESCRIPTION "just a test")

add_executable(testtorch
	       main.cpp)

#get_target_property(TORCH_INCLUDE_DIR torch INCLUDE_DIRECTORIES)

target_compile_features(testtorch PRIVATE cxx_std_17)
target_link_libraries(testtorch PRIVATE torch torch_cpu)
#target_include_directories(testtorch PRIVATE ${TORCH_INCLUDE_DIRECTORIES})
