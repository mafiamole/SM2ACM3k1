
set (HEADERS 

    ${MB_INCLUDE_DIR}/client/Game.hpp 
    ${MB_INCLUDE_DIR}/client/HUD.h
    ${MB_INCLUDE_DIR}/client/UI/UI_Elements.hpp
    ${MB_INCLUDE_DIR}/client/Map.h 
    ${MB_INCLUDE_DIR}/client/MapLoader.h
    ${MB_INCLUDE_DIR}/client/Players/PlayerInformation.hpp
    ${MB_INCLUDE_DIR}/client/Player.h
    ${MB_INCLUDE_DIR}/client/tcp_net.h
  )


set (SOURCES 
    Game.cpp
    Main.cpp
    Map.cpp
    HUD.cpp
    MapLoader.cpp
    UI/UI_Elements.cpp
    tcp_net.cpp
    Players/PlayerInformation.cpp
    Player.cpp
    )


add_executable(client ${HEADERS} ${SOURCES} )

include_directories (${MoleBox_INCLUDE_DIRECTORIES} ${LUA_INCLUDE_DIR} )

target_link_libraries( client ${MoleBox_LIBRARIES} ${LUA_LIBRARIES} )


add_subdirectory(Players)
