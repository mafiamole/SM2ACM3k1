cmake_minimum_required(VERSION 2.8)

set (HEADERS 

	${MB_INCLUDE_DIR}/server/Game.hpp
	${MB_INCLUDE_DIR}/shared/Packets.h
	${MB_INCLUDE_DIR}/server/tcp_net_serv.h)

set (SOURCES TCP_Net_Serv2.cpp 
	Game.cpp 
	Main.cpp
	../shared/Packets.cpp
	tcp_net_serv.cpp)

add_executable(server ${HEADERS} ${SOURCES} )

target_link_libraries( server ${MoleBox_LIBRARIES})
