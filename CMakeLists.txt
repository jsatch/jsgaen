cmake_minimum_required(VERSION 2.8.9)

project(js_framework)
set(CMAKE_BUILD_TYPE release) 

if(WIN32)
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:\\Users\\Hernan\\Development\\games\\jsgaen\\cmake")
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)

include_directories(include ${SDL2_INCLUDE_DIR} ${SDL2_LIBS} ${SDL2_DLLS} ${SDL2_IMAGE_INCLUDE_DIR}  ${SDL2_IMAGE_LIBRARIES})

file(GLOB SOURCES "src/*.cpp")

add_library(jsgaen SHARED ${SOURCES})

target_link_libraries(jsgaen ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

install(TARGETS jsgaen
		RUNTIME DESTINATION build/bin
        LIBRARY DESTINATION build/lib)