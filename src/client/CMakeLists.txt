
set (HEADERS 

    ${MB_INCLUDE_DIR}/client/Game.hpp 
    ${MB_INCLUDE_DIR}/client/HUD.h
    ${MB_INCLUDE_DIR}/client/UI/UI_Elements.hpp
    ${MB_INCLUDE_DIR}/client/Map.h 
    ${MB_INCLUDE_DIR}/client/ClientMapLoader.h
    ${MB_INCLUDE_DIR}/client/Players/PlayerInformation.hpp
    ${MB_INCLUDE_DIR}/client/Player.h
    ${MB_INCLUDE_DIR}/shared/MapLoader.h
    ${MB_INCLUDE_DIR}/shared/randomc.h
    ${MB_INCLUDE_DIR}/shared/Packets.h
    ${MB_INCLUDE_DIR}/shared/Enums.h
    ${MB_INCLUDE_DIR}/shared/SharedRoutines.hpp
    ${MB_INCLUDE_DIR}/client/Map/Tile.hpp
    ${MB_INCLUDE_DIR}/client/WorkQueues.h
    ${MB_INCLUDE_DIR}/client/UI/UI_LuaFunctions.hpp
    ${MB_INCLUDE_DIR}/client/TCP_Net2.hpp
    ${MB_INCLUDE_DIR}/client/Items.h

  )
    

set (SOURCES 
    Game.cpp
    Main.cpp
    Map.cpp
    HUD.cpp
    ClientMapLoader.cpp
    UI/UI_Elements.cpp
    #UI/UI_LuaFunctions.cpp
    Players/PlayerInformation.cpp
    Player.cpp
    ../shared/MapLoader.cpp
    ../shared/mersenne.cpp
    ../shared/Packets.cpp
    ../shared/SharedRoutines.cpp
    Map/Tile.cpp
    SpriteSheet.cpp
    WorkQueues.cpp
    SpriteSheetAnimator.cpp
    TCP_Net2.cpp
    Items.cpp
    Players.cpp
    )


add_executable(client ${HEADERS} ${SOURCES} )

include_directories (${MoleBox_INCLUDE_DIRECTORIES} ${LUA_INCLUDE_DIR} )

target_link_libraries( client ${LIBRARIES} )


add_subdirectory(Players)

add_subdirectory(Map)