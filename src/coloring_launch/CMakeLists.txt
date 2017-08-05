cmake_minimum_required(VERSION 2.8.3)
project(coloring_launch)
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g")

find_package(catkin
  REQUIRED COMPONENTS
  std_msgs
  sensor_msgs
  rospy
  roscpp
  roslint
)

catkin_package(CATKIN_DEPENDS std_msgs sensor_msgs)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(camera_timestamp src/camera_timestamp.cpp)
target_link_libraries(camera_timestamp ${catkin_LIBRARIES})

roslint_cpp()

