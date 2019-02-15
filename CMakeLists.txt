cmake_minimum_required(VERSION 2.6)
project(space-mission)

if (WIN32)
    set(SFML_DIR SFML/lib/cmake/SFML)
endif (WIN32)
# set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_STANDARD 11)

add_executable(space-mission main.cpp)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(SFML/include)
# link_directories(SFML-2.5.1\lib)
link_directories(D:/Nauka/Gry\ w\ c++/space-mission/SFML/lib)

find_package(SFML 2.5 COMPONENTS graphics audio system window REQUIRED)
target_link_libraries(space-mission sfml-graphics sfml-audio sfml-system sfml-window)
# target_link_libraries(space-mission ${SFML_LIBRARIES} ${SFML_DEPEDENCIES})
# target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
