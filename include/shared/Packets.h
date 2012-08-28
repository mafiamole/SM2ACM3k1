#ifndef Packets_H
#define Packets_H

#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <shared/Enums.h>

enum PacketTypes2 {
  
  SERVER_INITALISE = 0,
  CLIENT_SEND_POS,
  CLIENT_SEND_BONUS,
  SERVER_SEND_POS,
  SERVER_SEND_HP,
  SERVER_SEND_KILL,
  CLIENT_SEND_ATTACK,
  SERVER_SEND_ITEM_COLLECT,
  SERVER_SEND_NEWITEM,
  CLIENT_SEND_HIT_SPIKES,
  CLIENT_SEND_USE_ITEM
  
};

class Packets{
public:
	Packets();
	sf::Packet CreateSendThisPlayerPos(sf::Vector2f playerPosition, float currDirectionFacing);
    sf::Packet CreateInitThisClient(Bonus specBonus);

};



#endif