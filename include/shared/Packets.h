#ifndef Packets_H
#define Packets_H

#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


class Packets{
public:
	Packets();
	sf::Packet CreateSendThisPlayerPos(sf::Vector2f playerPosition, float currDirectionFacing);





};








#endif