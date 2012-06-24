#ifndef Packets_H
#define Packets_H

#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <client/Player.h>
#include <iostream>


class Packets{
public:
	Packets();
	sf::Packet CreateSendThisPlayerPos(sf::Vector2i playerPosition, int currDirectionFacing);



};








#endif