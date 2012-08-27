cmake_minimum_required(VERSION 2.8)
project(SM2ACM3k1)

find_package(SFML 2.0 COMPONENTS system window graphics audio network REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLU REQUIRED)
find_package(Lua51)
find_package(MoleBox COMPONENTS Core Lua REQUIRED)

set (MB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories ( ${MB_INCLUDE_DIR} )
include_directories (${MoleBox_INCLUDE_DIRECTORIES} )
set (LIBRARIES ${MoleBox_LIBRARIES})
add_definitions(-DMB_STATIC)
add_subdirectory(src/shared)
add_subdirectory(src/server)
add_subdirectory(src/client)


