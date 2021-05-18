cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")


project(IntentRec)

file(GLOB project_SRCS 
	src/IntentRecognizerTest.cpp
	src/IntentRecognizer.cpp)
file(GLOB project_INCL include/*)

find_package(GTest REQUIRED)
include_directories( ${GTEST_INCLUDE_DIRS} )
enable_testing()

add_executable(IntentRecTest ${project_SRCS} ${project_INCL})
target_link_libraries(IntentRecTest ${GTEST_LIBRARIES} )

file(GLOB project_SRCS 
	src/main.cpp
	src/IntentRecognizer.cpp)
file(GLOB project_INCL include/*)
add_executable(IntentRec ${project_SRCS} ${project_INCL})