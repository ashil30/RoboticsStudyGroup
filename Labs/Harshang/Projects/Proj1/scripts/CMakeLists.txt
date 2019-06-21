cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(model_push SHARED model_push.cc)
target_link_libraries(model_push ${GAZEBO_LIBRARIES})

add_library(factory SHARED factory.cc)
target_link_libraries(factory ${GAZEBO_LIBRARIES})

add_library(plugin_tutorial SHARED plugin_tutorial.cc)
target_link_libraries(plugin_tutorial ${GAZEBO_LIBRARIES})
