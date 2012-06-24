
#include <client/Player.h>
#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Game.hpp>


#include <iostream>

Player::Player(MB::Game* game) : MB::GameComponent(game)
{
    playerSprite = MB::Content::NewSprite("C:\\Content\\Player2.png");
 
	// Player sprite is 63x38
	this->playerSprite.setOrigin(31,19);
    this->playerSprite.setPosition(600,350);
  
}

void Player::Update(sf::Time elapsed, MB::Types::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);

	int dirX = 0;
	int dirY = 0;
	if ( (this->actions->Exists("Player Move Up") && this->actions->Get("Player Move Up")->IsActive() ) ||
		 ( this->actions->Exists("Player Move Up Alt") && this->actions->Get("Player Move Up Alt")->IsActive())){
		dirY = -1;
	}

	if ( (this->actions->Exists("Player Move Down") && this->actions->Get("Player Move Down")->IsActive() ) ||
		 ( this->actions->Exists("Player Move Down Alt") && this->actions->Get("Player Move Down Alt")->IsActive())){
		dirY = 1;
	}

	if ( (this->actions->Exists("Player Move Left") && this->actions->Get("Player Move Left")->IsActive() ) ||
		 ( this->actions->Exists("Player Move Left Alt") && this->actions->Get("Player Move Left Alt")->IsActive())){
		dirX = -1;
	}

	if ( (this->actions->Exists("Player Move Right") && this->actions->Get("Player Move Right")->IsActive() ) ||
		 ( this->actions->Exists("Player Move Right Alt") && this->actions->Get("Player Move Right Alt")->IsActive())){
		dirX =1;
	}

	// Change position (based on elapsed time)
	float vectorX = dirX * 0.5f * (float)elapsed.asMilliseconds();  
	float vectorY = dirY * 0.5f * (float)elapsed.asMilliseconds();
    sf::Vector2f playerPos = this->playerSprite.getPosition();    

    playerPos.y = playerPos.y + vectorY;
    playerPos.x = playerPos.x + vectorX;

	this->playerSprite.setPosition(playerPos);

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

	this->playerSprite.setRotation(rotation);


}

void Player::Draw()
{
  
  this->game->DrawSprite(this->playerSprite);
  
  MB::GameComponent::Draw();
  
}

Player::~Player()
{

}
