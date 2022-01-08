cmake_minimum_required(VERSION 3.22)

project(external.dlib)

set(VERSION 0.1)
set(DESCRIPTION "DLIB")

message("-- Creating Target dlib::dlib")

# code inside the dlib directory, will create 
# dlib::dlib target and import it into global namespace
add_subdirectory(dlib)

message("-- Creating Target dlib::dlib - done")
