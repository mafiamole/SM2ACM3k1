cmake_minimum_required(VERSION 2.8)

set (HEADERS 

	${MB_INCLUDE_DIR}/server/Game.hpp
	${MB_INCLUDE_DIR}/server/PacketRoutines.h
	${MB_INCLUDE_DIR}/shared/Packets.h
	${MB_INCLUDE_DIR}/shared/Enums.h
	${MB_INCLUDE_DIR}/shared/randomc.h
	${MB_INCLUDE_DIR}/server/TCP_Net_Serv2.hpp
	${MB_INCLUDE_DIR}/shared/MapLoader.h
        ${MB_INCLUDE_DIR}/server/TCP_Net_Manager.h
        ${MB_INCLUDE_DIR}/server/Match.h
	${MB_INCLUDE_DIR}/shared/SharedRoutines.hpp)

set (SOURCES Match.cpp TCP_Net_Manager.cpp TCP_Net_Serv2.cpp
	PacketRoutines.cpp 
	Game.cpp 
	Main.cpp
	../shared/Packets.cpp
	../shared/mersenne.cpp
	../shared/SharedRoutines.cpp
	../shared/MapLoader.cpp)

add_executable(server ${HEADERS} ${SOURCES} )

target_link_libraries( server ${LIBRARIES})
