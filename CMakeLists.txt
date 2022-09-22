cmake_minimum_required(VERSION 3.24)

project(ToyRobot)

set(TARGET_NAME toy_robot)

set(SOURCE_FILES
    source/main.cpp
    source/direction.h
    source/robot.cpp
    source/robot.h)

add_executable(${TARGET_NAME} ${SOURCE_FILES})

add_executable (robot_test
    source/test/robot_test.cpp
    source/robot.cpp)

target_include_directories(robot_test
    PRIVATE source)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(robot_test ${GTEST_LIBRARIES})