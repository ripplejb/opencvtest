cmake_minimum_required(VERSION 3.21)
project(OpenCVCPP)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(main main.cpp resources/test.png)
target_link_libraries(main ${OpenCV_LIBS})

FILE(COPY resources/test.png DESTINATION "${CMAKE_BINARY_DIR}/resources")
