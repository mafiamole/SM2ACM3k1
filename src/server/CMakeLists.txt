cmake_minimum_required(VERSION 2.8)

set (HEADERS 

	${MB_INCLUDE_DIR}/server/Game.hpp
	${MB_INCLUDE_DIR}/server/tcp_net_serv.h)

set (SOURCES 
	Game.cpp 
	Main.cpp
	tcp_net_serv.cpp)

add_executable(server ${HEADERS} ${SOURCES} )

target_link_libraries( server ${MoleBox_LIBRARIES})
