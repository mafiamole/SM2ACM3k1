
set (HEADERS ${MB_INCLUDE_DIR}/client/Game.hpp)

set (SOURCES Game.cpp Main.cpp)

add_executable(client ${HEADERS} ${SOURCES} )

include_directories (${MoleBox_INCLUDE_DIRECTORIES} )

target_link_libraries( client ${MoleBox_LIBRARIES})

