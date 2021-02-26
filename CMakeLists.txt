cmake_minimum_required(VERSION 3.0)

project(OpenCV_Samples)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(sample1 sample1.cpp)

target_link_libraries(sample1 ${OpenCV_LIBS})