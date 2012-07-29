#include <shared/Packets.h>
#include <SFML/Network.hpp>

//  int packetID    ==        1	 - curr player position
//  float positionX
//  float PositionY
//  float dirFacing   ==		float representing rotation from 0 (facing up) (360 rotation, i.e. 180 is facing down).
//
//  -------------------------------------------
//
//  int packetID	==		2	-	first connection, set player bonus
//  int bonusID

//  -------------------------------------------
//  From server to client, position/direction of another player
//
//  int packetID    ==        3	 - curr player position
//  float positionX
//  float PositionY
//  float dirFacing   ==		float representing rotation from 0 (facing up) (360 rotation, i.e. 180 is facing down).
//  int playerID

Packets::Packets(){}

sf::Packet Packets::CreateSendThisPlayerPos(sf::Vector2f playerPosition, float currDirectionFacing){
	sf::Packet packet;
	int packetID = 1;
	packet << packetID << playerPosition.x << playerPosition.y << currDirectionFacing;
	return packet;
}