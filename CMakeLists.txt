cmake_minimum_required(VERSION 3.21)
project(OpenCVCPP)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Chapter1 Chapter1.cpp)
target_link_libraries(Chapter1 ${OpenCV_LIBS})

add_executable(Chapter2 Chapter2.cpp Chapter2.cpp)
target_link_libraries(Chapter2 ${OpenCV_LIBS})

add_executable(Chapter3 Chapter3.cpp Chapter3.cpp)
target_link_libraries(Chapter3 ${OpenCV_LIBS})

add_executable(Chapter4 Chapter4.cpp Chapter4.cpp)
target_link_libraries(Chapter4 ${OpenCV_LIBS})

add_executable(Chapter5 Chapter5.cpp Chapter5.cpp)
target_link_libraries(Chapter5 ${OpenCV_LIBS})

add_executable(Chapter6 Chapter6.cpp Chapter6.cpp)
target_link_libraries(Chapter6 ${OpenCV_LIBS})

add_executable(Chapter7 Chapter7.cpp Chapter7.cpp)
target_link_libraries(Chapter7 ${OpenCV_LIBS})

add_executable(Chapter8 Chapter8.cpp Chapter8.cpp)
target_link_libraries(Chapter8 ${OpenCV_LIBS})

FILE(COPY resources/ DESTINATION "${CMAKE_BINARY_DIR}/resources")
