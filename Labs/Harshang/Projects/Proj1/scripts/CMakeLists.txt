cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

#Uncomment to build plugin tutorial
#add_library(plugin_tutorial SHARED plugin_tutorial.cc)
#target_link_libraries(plugin_tutorial ${GAZEBO_LIBRARIES})

