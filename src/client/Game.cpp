#include <client/Game.hpp>
#include <MoleBox/Actions/Keyboard.hpp>
#include <MoleBox/Actions/Mouse.hpp>
#include <MoleBox/Lua/Component.hpp>
#include <client/Map.h>
#include <client/MapLoader.h>
#include <client/Game.hpp>
#include <client/UI/UI_Elements.hpp>
#include <client/randomc.h>
#include <client/tcp_net.h>


//sf::Sound sound;

Map mapObj = Map();
MapLoader mapLoader = MapLoader();
Game::Game(std::string windowName) : MB::Game(windowName)
{


  //this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Fullscreen);
  this->window = new sf::RenderWindow(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Default);
  


  mapObj = Map(this->window, mapLoader.ReadFile("C:\\Content\\map.txt"));

  //mapObj = Map(this->window, mapLoader.ReadFile("C:\\Content\\map.txt"));

  this->actionList.Register("Exit",new MB::Keyboard(sf::Keyboard::Escape));
  this->actionList.Register("Player Move Up",new MB::Keyboard(sf::Keyboard::W));
  this->actionList.Register("Player Move Down",new MB::Keyboard(sf::Keyboard::S));
  this->actionList.Register("Player Move Left",new MB::Keyboard(sf::Keyboard::A));
  this->actionList.Register("Player Move Right",new MB::Keyboard(sf::Keyboard::D));
  	
  this->actionList.Register("Player Move Up Alt",new MB::Keyboard(sf::Keyboard::Comma));
  this->actionList.Register("Player Move Down Alt",new MB::Keyboard(sf::Keyboard::O));
  this->actionList.Register("Player Move Right Alt",new MB::Keyboard(sf::Keyboard::E));


  this->player = (Player*)this->AddComponent(  new Player( this , &mapObj ) );
  //this->Hud    = (HUD*)this->AddComponent( new HUD(this,"HUD.lua") );
  //this->player = (Player*)this->AddComponent( new Player(this) ); 
  this->AddComponent(new MB::Lua::LuaComponent(this, "C:\\Content\\Music.lua") );



 
   // Start the thread (internally calls task.run())

}


Game::~Game(void)
{

}

void Game::Update(sf::Time elapsed, MB::Types::EventList *events)
{
	// Update HasFocus variable
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
    // Handle Keyboard input	(only if has focus)

	//if(this->HasFocus()){
		if (this->actionList.Exists("Exit") && this->actionList.Get("Exit")->IsActive()){
			this->window->close(); 
			exit(0);
		}
	//}
     
		// Here have a section which processes the work (received) packets queue
		while(WorkQueues::packetsToProcess().size() != 0){
			sf::Packet packet = WorkQueues::packetsToProcess().front(); 
			WorkQueues::packetsToProcess().pop();
			
			int packetID;
			packet >> packetID;
			
			switch(packetID){
			case 3: // Another player has moved. Update their info
				float positionX;
				float positionY;
				float dirFacing; 
				int playerID;

				packet >> positionX >> positionY >> dirFacing >> playerID;

				bool alreadyExists = false;
				int indexFoundAt = 0;
				int currInd = 0;
				for (vector<PlayerData>::iterator pIT = remotePlayers.begin(); pIT != remotePlayers.end(); ++pIT)
				{
					PlayerData pData = *pIT;
					if(pData.playerID == playerID){ alreadyExists = true; indexFoundAt = currInd; }
					currInd++;
				}
				PlayerData tmpPlayer;
				if(!alreadyExists){ 
					remotePlayers.push_back(tmpPlayer); 
					indexFoundAt = remotePlayers.size() -1;  
					remotePlayers.at(indexFoundAt).playerID = playerID;
					remotePlayers.at(indexFoundAt).playerSprite = MB::Content::NewSprite("C:\\Content\\Player2.png");
					remotePlayers.at(indexFoundAt).playerSprite.setOrigin(31,19);
				}
					
				remotePlayers.at(indexFoundAt).position.x = positionX;
				remotePlayers.at(indexFoundAt).position.y = positionY;
				remotePlayers.at(indexFoundAt).direction = dirFacing;

				remotePlayers.at(indexFoundAt).playerSprite.setPosition(sf::Vector2f(positionX,positionY));
	         	remotePlayers.at(indexFoundAt).playerSprite.setRotation(dirFacing);

				//if(!((remotePlayers.size() -1) >= playerID)){
				//	// Player doesn't exist in list yet

				//}
				 

				break;
			
			}

		}


  MB::Game::Update(elapsed,events);
  
}

void Game::Draw()
{
	mapObj.Draw();


  // loop through other players and draw them
  for (vector<PlayerData>::iterator pIT = remotePlayers.begin(); pIT != remotePlayers.end(); ++pIT)
  {
					PlayerData pData = *pIT;
					this->DrawSprite(pData.playerSprite);
  }
	
  
  MB::Game::Draw();  
  
}

int Game::Run(int argc,char **argv)
{
  ClientTCP clientTCP(this);

  ThreadClass threadClass(clientTCP.clientTCP);
  sf::Thread thread(&ThreadClass::Run, &threadClass);

  CRandomMersenne rand(23232);
  //printf("%i",rand.IRandom(0,100));

	thread.launch();
	MB::Game::Run(argc,argv);
	thread.wait();
  return 0;
}


Player* Game::GetPlayer(){
	return this->player;
}

bool Game::HasFocus(){
	return this->hasFocus;
}



// Maybe use a stack instead of a queue, and process only the latest of each message - to avoid updating multiple positions etc needlessly.