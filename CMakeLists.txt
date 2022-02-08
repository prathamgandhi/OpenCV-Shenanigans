cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project(cvtest VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cvtest transition.cpp)
set(OpenCV_DIR "/home/pratham/C++Projects/OpenCV/opencv-build/installation/OpenCV-master/lib/cmake/opencv4")
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( cvtest ${OpenCV_LIBS} )
set(OpenCV_Path "/home/pratham/C++Projects/OpenCV/opencv-build/installation/OpenCV-master/lib/cmake/opencv4")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

