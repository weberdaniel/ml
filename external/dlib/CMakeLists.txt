# Author: Daniel Weber
# About: This shall build dlib. There is only one way to build it.
#        pull it in with add_subdirectory(dlib) and it will automatically
#        create target dlib::dlib. This is recommended because it is only
#        way to enable debug mode.
cmake_minimum_required(VERSION 3.22)

project(external.dlib)

set(VERSION 0.1)
set(DESCRIPTION "DLIB")

message("-- Creating Target dlib::dlib")

# note for dlib, the direct method of download and adding it
# via add_subdirectory is recommended, there exist no ubuntu
# or other packages for operating systems, this has several
# advantages, e.g. to turn on debug mode

# code inside the dlib directory, will create 
# dlib::dlib target and import it into global namespace
add_subdirectory(dlib)

message("-- Creating Target dlib::dlib - done")
