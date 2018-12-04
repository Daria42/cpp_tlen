cmake_minimum_required(VERSION 3.6)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(petrova_d_a)
include_directories(prj.labs)
add_subdirectory(prj.labs)
