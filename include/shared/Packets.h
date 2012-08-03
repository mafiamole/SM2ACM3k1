#ifndef Packets_H
#define Packets_H

#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <shared/Enums.h>


class Packets{
public:
	Packets();
	sf::Packet CreateSendThisPlayerPos(sf::Vector2f playerPosition, float currDirectionFacing);
    sf::Packet CreateInitThisClient(Bonus specBonus);

};








#endif