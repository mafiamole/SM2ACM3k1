#include <client/Game.hpp>
#include <MoleBox/Actions/Keyboard.hpp>
#include <MoleBox/Actions/Mouse.hpp>
#include <MoleBox/Lua/Component.hpp>
#include <client/Map.h>
#include <client/ClientMapLoader.h>
#include <shared/MapLoader.h>
#include <client/Game.hpp>
#include <client/UI/UI_Elements.hpp>
#include <shared/randomc.h>
#include <client/TCP_Net2.hpp>
#include <ctime>
#include <iostream>

Map mapObj = Map();
MapLoader mapLoader = MapLoader();
Game::Game(std::string windowName) : MB::Game(windowName)
{


  //this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Fullscreen);
  this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Default);
  
  mapObj = Map(this->window, ClientMapLoader::PopulateClientTileSprites(&mapLoader.ReadFile("map.txt")));

  this->actionList.Register("Exit",new MB::Keyboard(sf::Keyboard::Escape));
  this->actionList.Register("Player Move Up",new MB::Keyboard(sf::Keyboard::W));
  this->actionList.Register("Player Move Down",new MB::Keyboard(sf::Keyboard::S));
  this->actionList.Register("Player Move Left",new MB::Keyboard(sf::Keyboard::A));
  this->actionList.Register("Player Move Right",new MB::Keyboard(sf::Keyboard::D));
  	
  this->actionList.Register("Player Move Up Alt",new MB::Keyboard(sf::Keyboard::Comma));
  this->actionList.Register("Player Move Down Alt",new MB::Keyboard(sf::Keyboard::O));
  this->actionList.Register("Player Move Right Alt",new MB::Keyboard(sf::Keyboard::E));

  this->actionList.Register("UseItem", new MB::Keyboard(sf::Keyboard::U));
  this->actionList.Register("UseItem Alt", new MB::Keyboard(sf::Keyboard::F));

  this->actionList.Register("CheckHealth", new MB::Keyboard(sf::Keyboard::Num0));
  this->actionList.Register("CheckScore", new MB::Keyboard(sf::Keyboard::Num9));

  this->player = (Player*)this->AddComponent(  new Player( this , &mapObj ) );
  //this->Hud    = (HUD*)this->AddComponent( new HUD(this,"HUD.lua") );
  //this->player = (Player*)this->AddComponent( new Player(this) ); 
  //this->AddComponent(new MB::Lua::LuaComponent(this, "Music.lua") );


  // Generate random bonus id
  CRandomMersenne rand(time(0));  

  // Bonus is currently selected randomly, need to change this later
  Packets packets;
  WorkQueues::packetsToSend().push(packets.CreateInitThisClient((Bonus)rand.IRandom(1,3)));

}


Game::~Game(void)
{

}

void Game::Update(sf::Time elapsed, MB::Types::EventList *events)
{
	// Update HasFocus variable
    // Polling events, method 1
	/*int count = (*events).size();
	if(count  > 0){ cout << count << "\n"; }
	for (map<Event::EventType,Event>::iterator it = (*events).begin(); it != (*events).end(); ++it)
    {
		
		switch(it->first){
			case sf::Event::LostFocus:
				hasFocus = false;
	        break;
			case sf::Event::GainedFocus:
				hasFocus = true;
			break;
	    default:	
			break;
	    }
		
	}*/

    /// Polling events, method 2
	///*sf::Event e;
 //while (this->window->pollEvent(e))
 //{
 //   switch(e.type){
	//		case sf::Event::LostFocus:
	//			hasFocus = false;
	//        break;
	//		case sf::Event::GainedFocus:
	//			hasFocus = true;
	//		break;
	//    default:	
	//		break;
	//    }
 //}*/
    // Handle Keyboard input	(only if has focus - ideally)

	//if(this->HasFocus()){
        if (this->actionList.Exists("CheckHealth") && this->actionList.Get("CheckHealth")->IsActive() && allPlayers.size()>0){
            std::cout << "Health: ";
            for(int i=1; i<5;i++){
                std::cout << allPlayers.at(player->ownID).ReadHealth(&allPlayers.at(player->ownID),(HealthBits)i);
            }			
            std::cout << "\n";
		}

        if (this->actionList.Exists("CheckScore") && this->actionList.Get("CheckScore")->IsActive() && allPlayers.size()>0){
            std::cout << "Score: " << allPlayers.at(player->ownID).killCount << "\n";
		}


		if (this->actionList.Exists("Exit") && this->actionList.Get("Exit")->IsActive()){
			this->window->close(); 
			exit(0);
		}

        if (this->actionList.Exists("UseItem") && (this->actionList.Get("UseItem")->IsActive() ||
                                                   this->actionList.Get("UseItem Alt")->IsActive())){
            if(!allPlayers.at(this->player->ownID).item == PowerUp::NO_POWERUP){

                int packetID = 10;
                sf::Packet packet;
                packet << packetID << this->player->ownID;
                WorkQueues::packetsToSend().push(packet);

                // Do something depending on which item was currently equipped, then set equipped to null
                switch(allPlayers.at(this->player->ownID).item){
                case PowerUp::REPEL_NPC:
                        std::cout << "Player just used Repel NPC Item.\n";
                    break;

                }

                allPlayers.at(this->player->ownID).item = PowerUp::NO_POWERUP;
            }
		}
                 
	//}
     
		// Here have a section which processes the work (received) packets queue
		while(WorkQueues::packetsToProcess().size() != 0){
			sf::Packet packet = WorkQueues::packetsToProcess().front(); 
			WorkQueues::packetsToProcess().pop();
			
			int packetID;
			packet >> packetID;
			
			switch(packetID){
            case 0: // The game start packet that initialises the local copy of player data for each player.
                {
                  int playerCount;
                  packet >> playerCount;
                  int *IDsForWeapons = new int[playerCount];
                  float *positionX = new float[playerCount];
                  float *positionY = new float[playerCount];
                  
                  // Need to loop through all data arrays and unpack each data element individually.
                    
                  for(int j=0; j<playerCount;j++){
                        packet >> IDsForWeapons[j] >> positionX[j] >> positionY[j]; 
                  }

                  packet >> this->player->ownID;
                  
                  for(int i=0; i < playerCount; i++){
                      // Add a new player to allPlayers, and flesh out the info, own data will be used also(at least partially)
                      PlayerData tmpPlayer;				 
					  allPlayers.push_back(tmpPlayer); 
					  allPlayers.at(i).playerSprite = MB::Content::NewSprite("Player2.png");
					  allPlayers.at(i).playerSprite.setOrigin(31,19);
				
					  allPlayers.at(i).position.x = positionX[i];
                      allPlayers.at(i).position.y = positionY[i];
                      allPlayers.at(i).playerSprite.setPosition(allPlayers.at(i).position);
                      allPlayers.at(i).weapon = IDsForWeapons[i];
                      
                      allPlayers.at(i).direction = 0.0f;
                      allPlayers.at(i).SetFullHealth(&allPlayers.at(i));
                      allPlayers.at(i).item = PowerUp::NO_POWERUP;
                      allPlayers.at(i).killCount = 0;
                  }
                

                  // Set pointer to own data in player class
                  //this->player->playerInformation = (&*(allPlayers.begin()) + (sizeof(PlayerData)*this->player->ownID)  );
                  // Set this player position from the received go packet.
                  //this->player->SetPosition(this->player->playerInformation->position);
                  this->player->SetPosition(allPlayers.at(this->player->ownID).position);
                }
                break;
			case 3: // A player has moved. Update their info
            {
                float positionX;
                float positionY;
				float dirFacing; 
				int playerID;

                packet >> positionX >> positionY >> dirFacing >> playerID;
			    
                allPlayers.at(playerID).position.x = positionX;
                allPlayers.at(playerID).position.y = positionY;
				allPlayers.at(playerID).direction = dirFacing;
                allPlayers.at(playerID).playerSprite.setPosition(sf::Vector2f(positionX,positionY));
				allPlayers.at(playerID).playerSprite.setRotation(dirFacing);

                // If player is self (in case of has been killed and new position generated) - This packet should only be sent to self under that circumstance. So can re-init items as well
                if(playerID == player->ownID){
                    player->SetPosition(allPlayers.at(playerID).position);
                    allPlayers.at(playerID).item = PowerUp::NO_POWERUP;
                }
				break;
            }
            case 4: // Someone lost health (could be self). Do whatever (trigger hurt animation, combat text etc)
            {
                int playerID;
                int newHealth;
                packet >> playerID >> newHealth;
                allPlayers.at(playerID).health = newHealth;
                break;
            }
            case 5: // Receive updated kill count from server and do whatever
            {
                int playerID;
                int newKillCount;
                packet >> playerID >> newKillCount;
                allPlayers.at(playerID).killCount = newKillCount; 
                break;
            }
            case 7: // Remove item   -- if index is -1, then don't remove from floor
            {
			 int playerID;
             bool isWeapon;  
             int itemCode;      
             int itemIndex;

             packet >> playerID >> isWeapon >> itemCode >> itemIndex;

             if(isWeapon){
                allPlayers.at(playerID).weapon = itemCode;
             }else{
                allPlayers.at(playerID).item = itemCode;
             }
             
             if(!(itemIndex == -1)){
                allItems.erase(allItems.begin() + itemIndex);
             }   
             
             break;
            }
            case 8: // Put new items on the floor,
            {
                bool isWeapon;
                ClientItem tempItem;
              
                packet >> isWeapon >> tempItem.ItemID >> tempItem.position.x >> tempItem.position.y;                

                if(isWeapon){ tempItem.tileType = TileTypes::WEAPON; }else{ tempItem.tileType = TileTypes::ITEM; }

                // Need a better item/tile/sprite handling...
                tempItem.itemSprite = MB::Content::NewSprite("ItemTileSheet.png");
                tempItem.itemSprite.setPosition(tempItem.position.x,tempItem.position.y);
                
                //13*32 // row;
                //1*32 // col;
                sf::IntRect rect = sf::IntRect(32,13*32,32,32);
                tempItem.itemSprite.setTextureRect(rect);

                allItems.push_back(tempItem);
                // new item appeared on floor (could have been dropped by another player, or randomly spawned)


                break;
            }
            case 10: // A player just used their equipped item
            {
                int playerID;
                packet >> playerID;
                // Clear player's item.
                allPlayers.at(playerID).item = PowerUp::NO_POWERUP;
                std::cout << "Player " << playerID << " just used their item.\n";
                // This will NOT be sent to originating client. Originating client deals with the item use on send (see the keypress above)
                break;
            }
			}

		}


  MB::Game::Update(elapsed,events);
  
}

void Game::Draw()
{
    // Draw map tiles first
	mapObj.Draw();

    // Loop and draw all items
    for(int i=0; i < allItems.size();i++){
        this->DrawSprite(allItems.at(i).itemSprite);
    }

   // Loop through other players and draw them
    for(int i=0; i < allPlayers.size();i++){
        if(i != this->player->ownID){
            this->DrawSprite(allPlayers.at(i).playerSprite);
        }
    }

   
  MB::Game::Draw();  
  
}

int Game::Run(int argc,char **argv)
{
  ConnectionInfo info;
  //info.address = "86.185.77.64";
  info.address = "127.0.0.1";
  info.port = 4000;
  info.attempts = 3;
  info.timeout = 300;
  sf::Thread tcpThread(&TCP_Net_Thead2,info);
  
  tcpThread.launch();
  MB::Game::Run(argc,argv);
  tcpThread.wait();

  return 0;
}


Player* Game::GetPlayer(){
	return this->player;
}

bool Game::HasFocus(){
	return this->hasFocus;
}



// Maybe use a stack instead of a queue, and process only the latest of each message - to avoid updating multiple positions etc needlessly, tricky with them arriving out of order, maybe?