
set (HEADERS ${MB_INCLUDE_DIR}/client/Game.hpp ${MB_INCLUDE_DIR}/client/UIComponent.hpp ${MB_INCLUDE_DIR}/client/UI/UI_Elements.hpp )

set (SOURCES Game.cpp Main.cpp UIComponent.cpp UI/UI_Elements.cpp)
find_package(Lua51 REQUIRED)
add_executable(client ${HEADERS} ${SOURCES} )

include_directories ( ${MoleBox_INCLUDE_DIRECTORIES} ${LUA_INCLUDE_DIR} )

target_link_libraries( client ${MoleBox_LIBRARIES} ${LUA_LIBRARY})

add_subdirectory(Content)