
set (HEADERS 

    ${MB_INCLUDE_DIR}/client/Game.hpp 
    ${MB_INCLUDE_DIR}/client/UIComponent.hpp 
    ${MB_INCLUDE_DIR}/client/UI/UI_Elements.hpp
    ${MB_INCLUDE_DIR}/client/Map.h 
    ${MB_INCLUDE_DIR}/client/MapLoader.h
    ${MB_INCLUDE_DIR}/client/PlayerInformation.hpp
    
  )

set (SOURCES 
    Game.cpp
    Main.cpp
    Map.cpp
    MapLoader.cpp
    UIComponent.cpp
    UI/UI_Elements.cpp
    )


add_executable(client ${HEADERS} ${SOURCES} )

include_directories (${MoleBox_INCLUDE_DIRECTORIES} ${LUA_INCLUDE_DIR} )

target_link_libraries( client ${MoleBox_LIBRARIES} ${LUA_LIBRARIES} )


add_subdirectory(Player)