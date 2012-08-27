#ifndef ENUMS_H
#define ENUMS_H

#include <SFML/Graphics.hpp>

const int PLAYER_WIDTH = 63;
const int PLAYER_HEIGHT = 38;

enum PacketTypes
{   // Suffix denotes sender application, so server should check those suffixed CLIENT etc.
    INITIALISATION_SERV,
    PLAYER_POSITION_CLIENT,
    SET_PLAYER_INFO_CLIENT,
    PLAYER_POSITION_SERV,
    UPDATE_HEALTH_SERV,
    UPDATE_SCORE_SERV,
    ATTACK_MADE_CLIENT,
    ITEM_RECEIVED_SERV,
    NEW_ITEM_ON_FLOOR_SERV,
    PLACEHOLDER_UNUSED_PACKET,
    ITEM_USED_BOTH
};

enum Weapons
{        
    NO_WEAPON,
    SWORD,
    TRIDENT,
    BOW,    
    CLUB,
    SLINGSHOT,
    SPEAR,
    WARHAMMER,
    AXE,
    FLAIL,
    THROWING_AXE,
    SEVERED_ARM,
    POISON_DAGGER,
    GOAT_LEG,
    HAND_CANNON,
    SWORD_FISH,
    MINE,
    FIRE_WALL
};


enum Bonus{
    NO_BONUS,
    SHORT,
    LONG,
    RANGED
};


enum PowerUp{
    NO_POWERUP,
    REPEL_NPC,
    SPEED,
    ARMOUR,
    TINY_SIZE,
    BIG_SIZE,
    INVISIBILITY,
    INVULNERABILITY,
    AOE_ARROWS
};

enum Maps{
    NO_MAP,
    COLOSSEUM
};

enum TileTypes{
    NO_TILE_TYPE,
    FLOOR,
    CONTACT_DAMAGE,
    ITEM,
    WEAPON,
    WALL
};



/**
 *  
 *  Health is a single integer where,
 *  - least significant bit is the front health segment.
 *  - second significant bit is the back health segment.
 *  - third significant bit is the left health segment.
 *  - forth significant bit is the right health segment.
 * 
 */ 

enum HealthBits{
    NO_HEALTH,
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

struct Tile{
    sf::Vector2f position;
    TileTypes tileType;
};  

struct Item : Tile 
{
    int ItemID;
};

struct ClientItem : Item
{
    sf::Sprite itemSprite;
};
#endif