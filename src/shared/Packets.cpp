#include <shared/Packets.h>
#include <SFML/Network.hpp>

//  server to client
//  int packetID        ==        0  - All clients have connected and selected their bonus, update clients with start game and the starting position / weapon of each player
//                                   - this needs to make sure the client knows the correct player id of all players, including self
//                                   - clients can init all other info such as full health, zero'd kill count etc.
//  int playerCount
//  int IDsForWeapons[]
//  float positionX[]
//  float positionY[]
//  int yourID                       - the index for the arrays where this player is stored

//  [Dev-Status]                     - Done - In the future, the client should wipe list of remote players and prepare for a new round.


//  -------------------------------------------
//  client to server
//  int packetID        ==        1	 - curr player position
//  float positionX
//  float PositionY
//  float dirFacing     ==		     - float representing rotation from 0 (facing up) (360 rotation, i.e. 180 is facing down).

//  [Dev-Status]                     - Done

//  -------------------------------------------
//  client to server
//  int packetID	    ==		  2	 - On connection, set player bonus,  (player pos needs to have been randomly selected by server and ensuring not colliding with scenery)
//  int bonusID

//  [Dev-Status]                     - Working Temporary implementation. Player may be able to 'spawn' inside walls/floors still, and is unable to select bonus (randomly chosen atm)

//  -------------------------------------------
//  From server to client, position/direction of another player//
//  int packetID        ==        3	 - curr player position
//  float positionX
//  float PositionY
//  float dirFacing     ==		     - float representing rotation from 0 (facing up) (360 rotation, i.e. 180 is facing down).
//  int playerID

//  [Dev-Status]                     - Done

//  ---------------------------------------------
//  server to client
//  int packetID        ==        4  - Player updated health  (can be sent when health is lost, or to re-init a player on death   
//                                     Have option to send to all but orig sender (when hitting spikes player client already knows lost health)
//  int playerID
//  int newHealth

//  [Dev-Status]                     - Not Started

//  ---------------------------------------------
//  Server to client
//  int packetID        ==        5  - Update player kill count
//  int playerID
//  int newKillCount


//  [Dev-Status]                     - Not Started

//  --------------------------------------------
//  client to server (serv checks if a coll is made with another player) && server to client (send back out to all but orig sender)
//  int packetID        ==        6  - player has made an attack
//  playerID

//  [Dev-Status]                     - Not Started

//  --------------------------------------------
//  server to client
//  int packetID        ==        7  - a player just got a powerup / weapon (could be self)
//  int playerID
//  bool isWeapon                    - maintaining two lists of items, powerups and weapons. this sets which list to check.
//  int itemCode      
//  int itemIndex                    - the index for internal list of items currently on floor. Client can use this to remove item from list so it doesn't display any more.
//                                    

//  [Dev-Status]                     - Done, slightly untested

//  ---------------------------------------------
//  server to client
//  int packetID        ==        8  - new item appeared on floor (could have been dropped by another player, or randomly spawned)
//  bool isWeapon
//  int itemCode
//  float positionX
//  float positionY

//  [Dev-Status]                     - Done

//  --------------------------------------------
//  client to server
//  int packetID        ==        9  - player hit some spikes
//  int newHealth
//  float dirFacing
//  float positionX
//  float PositionY

//  [Dev-Status]                     - Not Started (should implement knock-back system fully first)  -- may not strictly be necessary, as can be done with other packets.

//  ---------------------------------------------
//  client to server
//  int packetID        ==        10  - a player just used their equipped item/power-up
//  int playerID

//  [Dev-Status]                     - Done, slightly untested



////////////////////
///////////////////
//  Still need packets for: knockback / animation info / game timer / game events (lion)/ ranged weapons



Packets::Packets(){}
// Client Side packets
sf::Packet Packets::CreateSendThisPlayerPos(sf::Vector2f playerPosition, float currDirectionFacing){
	sf::Packet packet;
	int packetID = 1;
	packet << packetID << playerPosition.x << playerPosition.y << currDirectionFacing;
	return packet;
}
sf::Packet Packets::CreateInitThisClient(Bonus specBonus){
	sf::Packet packet;
	int packetID = 2;
	packet << packetID << specBonus;
	return packet;
}


// Server side packets

