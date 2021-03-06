cmake_minimum_required(VERSION 3.0)

project(MagicCube)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if(UNIX AND NOT APPLE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -no-pie")
endif()


find_package(Qt5 REQUIRED Core OpenGL)
find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

FILE(GLOB SRC_FILES "./*.cpp")
FILE(GLOB HEAD_FILES "./*.h")
FILE(GLOB UI_FILES "./*.ui")
FILE(GLOB QRC_FILES "./*.qrc")

add_executable(MagicCube ${SRC_FILES} ${HEAD_FILES} )
target_link_libraries(MagicCube ${OPENGL_LIBRARIES})

qt5_use_modules(MagicCube Core OpenGL)

