#include <iostream>

#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Game.hpp>


#include <client/Game.hpp>
#include <client/Players.h>
#include <client/Player.h>
#include <client/Map.h>


Player::Player(MB::Game* game, Map* map) : MB::GameComponent(game), gameMap(map)
{
    std::string pathPrefix = "";

    playerSprite = MB::Content::NewSprite("Player2.png");

    // Player sprite is 63x38

    this->playerSprite.setOrigin(31,19);
    this->playerSprite.setPosition(531,519);

    UpdateWeaponHitBox();
    
    attackedRect.setOutlineColor(sf::Color::Red);
    attackedRect.setFillColor(sf::Color::Transparent);
    attackedRect.setOutlineThickness(3);
}


Player::~Player()
{

}

void Player::SetPlayers(Players* players)
{
  this->players = players;
}

void Player::Update(sf::Time elapsed, MB::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);

    int dirX = 0;
    int dirY = 0;
    bool moved = false;

    sf::Vector2f origPos(this->playerSprite.getPosition());
    float origRot = this->playerSprite.getRotation();

    Game* g = (Game*)this->game;


    /*if(g->HasFocus()){*/
    if ( (this->actions->Exists("Player Move Up") && this->actions->Get("Player Move Up")->IsActive() ) ||
            ( this->actions->Exists("Player Move Up Alt") && this->actions->Get("Player Move Up Alt")->IsActive())) {
        dirY = -1;
        moved = true;
    }

    if ( (this->actions->Exists("Player Move Down") && this->actions->Get("Player Move Down")->IsActive() ) ||
            ( this->actions->Exists("Player Move Down Alt") && this->actions->Get("Player Move Down Alt")->IsActive())) {
        dirY = 1;
        moved = true;
    }

    if ( (this->actions->Exists("Player Move Left") && this->actions->Get("Player Move Left")->IsActive() ) ||
            ( this->actions->Exists("Player Move Left Alt") && this->actions->Get("Player Move Left Alt")->IsActive())) {
        dirX = -1;
        moved = true;
    }

    if ( (this->actions->Exists("Player Move Right") && this->actions->Get("Player Move Right")->IsActive() ) ||
            ( this->actions->Exists("Player Move Right Alt") && this->actions->Get("Player Move Right Alt")->IsActive())) {
        dirX = 1;
        moved = true;
    }

    //}


    sf::Vector2f direction(dirX,dirY);


    // Change position (based on elapsed time)
    // Limit elapsed time first
    float limitedElapsed = (float)elapsed.asMilliseconds();
    if(limitedElapsed > 31.0f) {
        limitedElapsed = 31.0f;
    }

    sf::Vector2f velocity(dirX * 1.f * limitedElapsed, dirY * 1.f * limitedElapsed);

    // Now check collision

    sf::IntRect origRect(this->playerSprite.getGlobalBounds());
    origRect.top = origPos.y;
    origRect.left = origPos.x;
    origRect.width = origRect.height = 32;

    // Slight offset correction (from origin)
    origRect.top -= 16;
    origRect.left -= 16;

    sf::Vector2f correctedVector = gameMap->collisionDetect(origRect, velocity, direction ) ;

    correctedVector.x += origPos.x;
    correctedVector.y += origPos.y;

    this->playerSprite.setPosition(correctedVector);

    // Set sprite orientation based on dir
    float rotation = 0.0f;

    // Diagonals

    if(dirY == -1 && dirX == -1) {
        rotation = 315.0f;
    } else if(dirY == -1 && dirX == 1) {
        rotation = 45.0f;
    } else if(dirY == 1 && dirX == -1) {
        rotation = 225.0f;
    } else if(dirY == 1 && dirX == 1) {
        rotation = 135.0f;
    }

    if(rotation == 0.0f) {
        if(dirY == 1) {
            rotation = 180.0f;
        } else if(dirX == -1) {
            rotation = 270.0f;
        } else if(dirX == 1) {
            rotation = 90.0f;
        }
    }

    this->playerSprite.setRotation(rotation);


    if(moved) {
        // Update the local copy of weapon hitbox only if moved
        UpdateWeaponHitBox();
        this->directionVector = sf::Vector2i(dirX,dirY);
        // Send Packet
        Packets packets;
        WorkQueues::packetsToSend().push(packets.CreateSendThisPlayerPos(playerSprite.getPosition(),playerSprite.getRotation()));

    } else {
        this->playerSprite.setRotation(origRot);
    }

    
    if (
	(this->actions->Exists("UseItem") && this->actions->Get("UseItem")->IsActive()) ||
        (this->actions->Exists("UseItem Alt") && this->actions->Get("UseItem Alt")->IsActive())
       ) 
    {
      this->UseItem();
    }
    this->attacking = false;
    if (this->game->GetActions()->Exists("Attack") && this->game->GetActions()->Get("Attack")->IsActive())
    {
	this->attacking = true;
        this->Attack();

    }
}

sf::IntRect Player::GetHitBox() {
    return sf::IntRect(this->playerSprite.getPosition().x - 15,
                       this->playerSprite.getPosition().y - 3, 32, 32);
    //return sf::IntRect(this->playerSprite.getGlobalBounds().left + 15,
    /*this->playerSprite.getGlobalBounds().top + 3,
    this->playerSprite.getGlobalBounds().width - 31,
    this->playerSprite.getGlobalBounds().height - 6);   */
}

sf::Vector2f Player::HitBoxPosToBoundingPos(sf::Vector2f pos) {
    return sf::Vector2f(pos.x-15,pos.y-3);

}

sf::Vector2i Player::GetDirectionVector() {
    return this->directionVector;
}

void Player::Draw()
{

    this->game->DrawAsset(this->playerSprite);

    // Draw a hitbox for the weapon
    this->game->DrawAsset(this->weaponHitBox);
    
    if (attacking)
    {
      sf::RectangleShape attackShape;
      attackShape.setOutlineColor(sf::Color::Black);
      attackShape.setFillColor(sf::Color::Transparent);
      attackShape.setOutlineThickness(3);
      attackShape.setSize(sf::Vector2f(50,50));
      attackShape.setPosition( attackRect.left, attackRect.top );
      attackShape.setSize( sf::Vector2f( attackRect.width,attackRect.height) );
      this->game->DrawAsset(attackShape);
      this->game->DrawAsset(attackedRect);
    }

    MB::GameComponent::Draw();

}

void Player::UpdateWeaponHitBox() {
    sf::RectangleShape rectangle;

    rectangle.setOutlineColor(sf::Color::Magenta);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(3);
    int playerHeight = this->GetTextureRect().height;

    switch(this->bonus) {
    case SHORT:
        rectangle.setSize(sf::Vector2f(this->GetTextureRect().width, playerHeight*1.2));
        rectangle.setPosition(this->playerSprite.getPosition().x , this->playerSprite.getPosition().y  );
        rectangle.setOrigin(31, rectangle.getLocalBounds().height - 19);
        break;

    case LONG:
        rectangle.setSize(sf::Vector2f(this->GetTextureRect().width-20, playerHeight*2.2));
        rectangle.setPosition(this->playerSprite.getPosition().x , this->playerSprite.getPosition().y  );
        rectangle.setOrigin(21, rectangle.getLocalBounds().height - 19);
        break;
    }

    // Try and set origin to about players head center //

    rectangle.setRotation(this->playerSprite.getRotation());
    this->weaponHitBox = rectangle;
}

sf::Vector2f Player::GetPosition() {
    return this->playerSprite.getPosition();
}
void Player::SetPosition(float X, float Y) {
    this->playerSprite.setPosition(sf::Vector2f(X,Y));
}

void Player::SetPosition(sf::Vector2f vect) {
    this->playerSprite.setPosition(vect);
}

float Player::GetDirection() {
    return this->playerSprite.getRotation();
}

sf::IntRect Player::GetTextureRect() {
    return this->playerSprite.getTextureRect();
}




/**
 * @brief Call when you register an attack action. This function will send the weapon hitbox to the server.
 * @author mafiamole@gmail.com
 * @return void
 **/
void Player::Attack()
{
    int otherPlayerId;
    if(this->ownID == 0) {
        otherPlayerId = 1;
    }
    else {
        otherPlayerId = 0;
    }

    // Get hit players rotation and postion.

    PlayerData otherPlayer = players->GetPlayerData(otherPlayerId);


    // build up a rect to represent the opponent. no need to rotate since position is relative to centre
    sf::RectangleShape otherPlayerRect;

    sf::Vector2f halfSprite = sf::Vector2f(this->playerSprite.getTextureRect().width / 2,this->playerSprite.getTextureRect().height / 2);

    otherPlayerRect.setTextureRect(this->playerSprite.getTextureRect());
    otherPlayerRect.setOrigin(halfSprite.x,halfSprite.y);
    otherPlayerRect.setPosition( otherPlayer.position.x,otherPlayer.position.y );

    // Build up a rect to represent a shadow of the weapon sprite

    //need to rotate sprite about otherplayer's centre.
    //Since the origin is relative to the top left corner of the sprite, we have to find out the relative postion from that point

    sf::Vector2f playerTopLeftPosition = sf::Vector2f
      (

	  this->weaponHitBox.getPosition().x - (this->weaponHitBox.getTextureRect().width / 2),
	  this->weaponHitBox.getPosition().y - (this->weaponHitBox.getTextureRect().height /2)

      );
    // get the origin relative too the top left of the player weapon hitbox.
    sf::Vector2f RelativeRotateOrigin = sf::Vector2f
      (
	  otherPlayerRect.getPosition() - playerTopLeftPosition
      );
    // create the new rectangle, cloning the weapon hitbox and setting this origin to the calculated one.
    sf::RectangleShape playerWeaponTempRect = this->weaponHitBox;

    playerWeaponTempRect.setOrigin(RelativeRotateOrigin.x,RelativeRotateOrigin.y);
    playerWeaponTempRect.rotate(otherPlayer.direction);

    // create packet.
    int packetID = ATTACK_MADE_CLIENT;
    sf::Packet packet;
    sf::FloatRect weaponRect = this->weaponHitBox.getGlobalBounds();
    sf::FloatRect revisedRect = playerWeaponTempRect.getGlobalBounds();

    this->attackRect = revisedRect;
    this->attackedRect = otherPlayerRect;
    packet << packetID << this->ownID
           << weaponRect.left << weaponRect.top << weaponRect.width << weaponRect.height
           << revisedRect.left << revisedRect.top << revisedRect.width << revisedRect.height;
    WorkQueues::packetsToSend().push(packet);
}
void Player::UseItem()
{

    int item = players->GetPlayerData(ownID).item; // lazy shortcut
    if(!(item == NO_POWERUP))
    {

        int packetID = ITEM_USED_BOTH;
        sf::Packet packet;
        packet << packetID << ownID;
        WorkQueues::packetsToSend().push(packet);

        // Do something depending on which item was currently equipped, then set equipped to null
        switch(item)
        {
        case REPEL_NPC:
            std::cout << "Player just used Repel NPC Item.\n ";
            break;
        default:
            std::cout << "Player used UNSPECIFIED item.\n";
            break;
        }

        players->UseEquiment(ownID);
    }
}
