#include <client/Game.hpp>
#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Actions/Keyboard.hpp>
#include <MoleBox/Actions/Mouse.hpp>
#include <MoleBox/Lua/Component.hpp>
#include <client/Map.h>


#include <client/Game.hpp>
#include <client/UI/UI_Elements.hpp>
#include <shared/randomc.h>

#include <ctime>
#include <iostream>

// Map mapObj = Map();
// MapLoader mapLoader = MapLoader();
Game::Game(std::string windowName,int argc,char** argv) : MB::Game(windowName,argc,argv)
{
    this->Config.LoadFile("Config.cfg");
    this->Config.LoadArgs(argc,argv);
    std::string ip = this->Config.GetStringValue("ip");
    if ( ip != "")
        info.address = ip;
    else
        info.address = "127.0.0.1";

    info.port = 4000;
    info.attempts = 3;
    info.timeout = 2000;

    //this->window->create(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Fullscreen);
    this->window->create(sf::VideoMode(1024 , 768, 32), "Super Mega Awesome Arena Colosseum multiplayer 3000 and 1", sf::Style::Default);

    mapObj = Map(this->window, ClientMapLoader::PopulateClientTileSprites(mapLoader.ReadFile("map.txt")));

    this->actions.Register("Exit",new MB::Actions::Keyboard(sf::Keyboard::Escape));
    this->actions.Register("Player Move Up",new MB::Actions::Keyboard(sf::Keyboard::W));
    this->actions.Register("Player Move Down",new MB::Actions::Keyboard(sf::Keyboard::S));
    this->actions.Register("Player Move Left",new MB::Actions::Keyboard(sf::Keyboard::A));
    this->actions.Register("Player Move Right",new MB::Actions::Keyboard(sf::Keyboard::D));

    this->actions.Register("Player Move Up Alt",new MB::Actions::Keyboard(sf::Keyboard::Comma));
    this->actions.Register("Player Move Down Alt",new MB::Actions::Keyboard(sf::Keyboard::O));
    this->actions.Register("Player Move Right Alt",new MB::Actions::Keyboard(sf::Keyboard::E));

    this->actions.Register("UseItem", new MB::Actions::Keyboard(sf::Keyboard::U));
    this->actions.Register("UseItem Alt", new MB::Actions::Keyboard(sf::Keyboard::F));

    this->actions.Register("Attack", new MB::Actions::Keyboard(sf::Keyboard::Space));

    this->actions.Register("CheckHealth", new MB::Actions::Keyboard(sf::Keyboard::Num0));
    this->actions.Register("CheckScore", new MB::Actions::Keyboard(sf::Keyboard::Num9));


    this->player = (Player*)this->AddComponent(  new Player( this , &mapObj ) );
    this->players = (Players*)this->AddComponent( new Players(player,this) );
    this->player->SetPlayers(players);

    //this->Hud    = (HUD*)this->AddComponent( new HUD(this,"HUD.lua") );
    //this->AddComponent(new MB::Lua::LuaComponent(this, "Music.lua") );


    // Generate random bonus id
    CRandomMersenne rand(time(0));

    // Bonus is currently selected randomly, need to change this later
    Packets packets;
    this->player->bonus = LONG;//;(Bonus)rand.IRandom(1,3);
    WorkQueues::packetsToSend().push(packets.CreateInitThisClient(this->player->bonus));

}


Game::~Game(void)
{

}

void Game::Update(sf::Time elapsed, MB::EventList *events)
{

    if (this->GetActions()->Exists("CheckHealth") && this->GetActions()->Get("CheckHealth")->IsActive() && players->Count()>0) {
        std::cout << "Health: ";
        PlayerData clientData = players->GetPlayerData(player->ownID);
        for(int i=1; i<5; i++) {
            // std::cout << allPlayers.at(player->ownID).ReadHealth( players->GetPlayerData() .at(player->ownID),(HealthBits)i);
            std::cout << clientData.ReadHealth(&clientData,(HealthBits)i);
        }
        std::cout << "\n";
    }

    if (this->GetActions()->Exists("CheckScore") && this->GetActions()->Get("CheckScore")->IsActive() && players->Count()>0) {
        PlayerData clientData = players->GetPlayerData(player->ownID);
        std::cout << "Score: " << clientData.killCount << "\n";
    }


    if (this->GetActions()->Exists("Exit") && this->GetActions()->Get("Exit")->IsActive()) {
        this->window->close();
        exit(0);
    }

    this->NetworkUpdate();

    MB::Game::Update(elapsed,events);

}

void Game::Draw()
{
    // Draw map tiles first
    mapObj.Draw();

    // Loop and draw all items
    for(int i=0; i < allItems.size(); i++) {
        this->DrawAsset(allItems.at(i).itemSprite);
    }



    MB::Game::Draw();

}

int Game::Run()
{
    //   ConnectionInfo info;
    //   //info.address = "127.0.0.1";
    //   info.address = "81.159.77.208";
    //   info.port = 4000;
    //   info.attempts = 3;
    //   info.timeout = 2000;
    sf::Thread tcpThread(&TCP_Net_Thead2,info);

    tcpThread.launch();
    MB::Game::Run();
    tcpThread.wait();

    return 0;
}


void Game::NetworkUpdate()
{
    while (WorkQueues::packetsToProcess().size() != 0)
    {

        sf::Packet packet = WorkQueues::packetsToProcess().front();

        WorkQueues::packetsToProcess().pop();

        int packetID;
        packet >> packetID;
        std::cout << "packet recieved " << packetID << std::endl;
        switch (packetID)
        {
        case INITIALISATION_SERV:
            {   // The game start packet that initialises the local copy of player data for each player.
                int playerCount;
                int weaponId;
                float xPos,yPos;
                packet >> playerCount;
                for (int plrCtr = 0; plrCtr < playerCount; plrCtr++)
                {
                    packet >> weaponId >> xPos >> yPos;
                    players->AddPlayer(weaponId,xPos,yPos);
                }
                packet >> this->player->ownID;
                player->SetPosition(players->GetPlayerPosition(player->ownID));
                break;
            }
        case PLAYER_POSITION_SERV: // A player has moved. Update their info
            {                
                float xPos,yPos,direction;
                int playerId;
                packet >> xPos >> yPos >> direction >> playerId;
                players->UpdatePlayerPosition(playerId,xPos,yPos,direction);
                break;
            }
        case UPDATE_HEALTH_SERV: // Someone lost health (could be self). Do whatever (trigger hurt animation, combat text etc)
            {
                int playerId;
                int newHealth;
                packet >> playerId >> newHealth;
                players->UpdatePlayerHealth(playerId,newHealth);
                break;
            }
        case UPDATE_SCORE_SERV: // Receive updated kill count from server and do whatever
            {
                int playerId;
                int newKillCount;
                packet >> playerId >> newKillCount;
                players->UpdateKillCount(playerId,newKillCount);
                break;
            }
        case ITEM_RECEIVED_SERV: // Remove item   -- if index is -1, then don't remove from floor
            {
                int playerId;
                bool isWeapon;
                int itemCode;
                int itemIndex;

                packet >> playerId >> isWeapon >> itemCode >> itemIndex;
                players->RemoveItem(playerId,isWeapon,itemCode,itemIndex);
                break;
            }
        case NEW_ITEM_ON_FLOOR_SERV:  // Put new items on the floor,
            {
                bool isWeapon;
                ClientItem tempItem;

                packet >> isWeapon >> tempItem.ItemID >> tempItem.position.x >> tempItem.position.y;
                if (isWeapon)
                {
                    tempItem.tileType = WEAPON;
                }
                else
                {
                    tempItem.tileType = ITEM;
                }

                tempItem.itemSprite = MB::Content::NewSprite("ItemTileSheet.png");
                tempItem.itemSprite.setPosition(tempItem.position.x,tempItem.position.y);
                sf::IntRect rect = sf::IntRect(32,13*32,32,32);
                tempItem.itemSprite.setTextureRect(rect);

                allItems.push_back(tempItem);
                break;
            }
        case PacketTypes::ITEM_USED_BOTH:    // A player just used their equipped item
            {
                int playerId;
                packet >> playerId;
                players->UseEquiment(playerId);
                break;
            }
        }

    }

}

void Game::RemoveItem(int index)
{

    allItems.erase(allItems.begin() + index);

}


// Maybe use a stack instead of a queue, and process only the latest of each message - to avoid updating multiple positions etc needlessly, tricky with them arriving out of order, maybe?
