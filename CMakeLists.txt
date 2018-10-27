cmake_minimum_required(VERSION 2.8.9)

project(js_framework)
set(CMAKE_BUILD_TYPE release)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/Users/hernan/development/gamedev/GameEngine/Framework/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)

include_directories(include ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR})

file(GLOB SOURCES "src/*.cpp")

add_library(jsgaen SHARED ${SOURCES})

target_link_libraries(jsgaen ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})


