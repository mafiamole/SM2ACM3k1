#ifndef ENUMS_H
#define ENUMS_H


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
    NONE,
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

#endif