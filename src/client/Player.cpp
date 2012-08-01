
#include <client/Player.h>
#include <client/Map.h>
#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Game.hpp>
#include <client/Game.hpp>
#include <iostream>

Player::Player(MB::Game* game, Map* map) : MB::GameComponent(game), gameMap(map)
{
	std::string pathPrefix = "";
	
    playerSprite = MB::Content::NewSprite("Player2.png");
 
	// Player sprite is 63x38
    
    this->playerSprite.setOrigin(31,19);
    this->playerSprite.setPosition(531,519);

    this->rect.left = 600;
    this->rect.height = 350;
    
}

void Player::Update(sf::Time elapsed, MB::Types::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);

	int dirX = 0;
	int dirY = 0;
	bool moved = false;

	 
	Game* g = (Game*)this->game;


	/*if(g->HasFocus()){*/
	if ( (this->actions->Exists("Player Move Up") && this->actions->Get("Player Move Up")->IsActive() ) ||
		 ( this->actions->Exists("Player Move Up Alt") && this->actions->Get("Player Move Up Alt")->IsActive())){
		dirY = -1; moved = true;
	}

	if ( (this->actions->Exists("Player Move Down") && this->actions->Get("Player Move Down")->IsActive() ) ||
		 ( this->actions->Exists("Player Move Down Alt") && this->actions->Get("Player Move Down Alt")->IsActive())){
		dirY = 1; moved = true;
	}

	if ( (this->actions->Exists("Player Move Left") && this->actions->Get("Player Move Left")->IsActive() ) ||
		 ( this->actions->Exists("Player Move Left Alt") && this->actions->Get("Player Move Left Alt")->IsActive())){
		dirX = -1; moved = true;
	}

	if ( (this->actions->Exists("Player Move Right") && this->actions->Get("Player Move Right")->IsActive() ) ||
		 ( this->actions->Exists("Player Move Right Alt") && this->actions->Get("Player Move Right Alt")->IsActive())){
		dirX = 1; moved = true;
	}
	
	//}


	sf::Vector2f direction(dirX,dirY);
	

	// Change position (based on elapsed time)
	float vectorX = dirX * 1.f * (float)elapsed.asMilliseconds();  
	float vectorY = dirY * 1.f * (float)elapsed.asMilliseconds();
		
	
	sf::Vector2f playerPos = this->playerSprite.getPosition();
	sf::IntRect collisionRect = this->playerSprite.getTextureRect();
	
	collisionRect.left = playerPos.x - ( collisionRect.width / 2); collisionRect.top = playerPos.y - ( collisionRect.height / 2);
	
	sf::IntRect collisionRectNext = collisionRect;
	
	collisionRectNext.left += vectorX;
	collisionRectNext.top  += vectorY;
	
	sf::Vector2f velocity(vectorX,vectorY);
	    
	sf::Vector2f nextPosition (playerPos.x + vectorX,playerPos.y + vectorY);

	sf::Vector2u windowSize = this->game->Window()->getSize();
	
	sf::IntRect windowRect(0,0,windowSize.x,windowSize.y);
	
	bool topLeft, topRight,bottomLeft,bottomRight;
	
	topLeft = windowRect.contains(collisionRectNext.left,collisionRectNext.top);
	
	topRight = windowRect.contains(collisionRectNext.left + collisionRectNext.width,collisionRectNext.top);
	
	bottomLeft = windowRect.contains(collisionRectNext.left,collisionRectNext.top + collisionRectNext.height);
	
	bottomRight = windowRect.contains(collisionRectNext.left + collisionRectNext.width,collisionRectNext.top + collisionRectNext.height);
	
	
	this->rect = collisionRectNext;
	sf::Vector2f newVector;
	
	bool hitobject = gameMap->collisionDetect(collisionRectNext, velocity,direction );
	
	sf::Vector2f newPosition = playerPos + newVector;
	
	if ( !(topLeft && topRight && bottomLeft && bottomRight))
	{
	  nextPosition = playerPos;
	}
	else {
	  nextPosition = nextPosition;
	  
	}
	
	if (hitobject)
	    nextPosition = playerPos;

	this->playerSprite.setPosition(nextPosition);

	// Set sprite orientation based on dir
	float rotation = 0.0f;

	// Diagonals

	if(dirY == -1 && dirX == -1){	
		rotation = 315.0f;		
	}else if(dirY == -1 && dirX == 1){
		rotation = 45.0f;
	}else if(dirY == 1 && dirX == -1){
		rotation = 225.0f;
	}else if(dirY == 1 && dirX == 1){
		rotation = 135.0f;
	}

	if(rotation == 0.0f){
	if(dirY == 1){
		rotation = 180.0f;
	}else if(dirX == -1){
		rotation = 270.0f;
	}else if(dirX == 1){
		rotation = 90.0f;
	}
	}

	//if(dirX == -1){ this->playerSprite.rotate(20.0f);  }
	//if(dirX == 1){ this->playerSprite.rotate(-20.0f); }

	

	if(moved){
		this->playerSprite.setRotation(rotation);
		Packets packets;
		WorkQueues::packetsToSend().push(packets.CreateSendThisPlayerPos(playerSprite.getPosition(),playerSprite.getRotation()));

	}

}

void Player::Draw()
{
  //sf::Vector2f rectSize;
  //rectSize.x = this->rect.width; rectSize.y = this->rect.height;
  //sf::RectangleShape shape = sf::RectangleShape(rectSize);
  
  //shape.setPosition(this->rect.left,this->rect.top);
  //this->game->DrawSprite(shape);

  this->game->DrawSprite(this->playerSprite);
  MB::GameComponent::Draw();
  
}

sf::Vector2f Player::GetPosition(){
	return this->playerSprite.getPosition();
}
void Player::SetPosition(float X, float Y){
	this->playerSprite.setPosition(sf::Vector2f(X,Y));
}

float Player::GetDirection(){
	return this->playerSprite.getRotation();
}

sf::IntRect Player::GetTextureRect(){
	return this->playerSprite.getTextureRect();
}

Player::~Player()
{

}

