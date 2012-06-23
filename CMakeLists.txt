cmake_minimum_required(VERSION 2.8)
project(SM2ACM3k1)
find_package(MoleBox REQUIRED)
find_package(Lua51)

set (MB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories ( ${MB_INCLUDE_DIR} )
include_directories (${MoleBox_INCLUDE_DIRECTORIES} )


add_subdirectory(src/server)
add_subdirectory(src/client)
add_subdirectory(include/client/Players)