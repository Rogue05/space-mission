cmake_minimum_required(VERSION 2.6)
project(space-mission)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(space-mission main.cpp Node.hpp)
target_link_libraries(space-mission sfml-graphics sfml-audio)