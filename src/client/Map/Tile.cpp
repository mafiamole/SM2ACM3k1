#include <client/Map/Tile.hpp>
#include <iostream>
/**
 * 
 * 
 *  Spikes
 * 
 */

ClientTile::ClientTile(){}
ClientTile::ClientTile(sf::Sprite sprite) : sprite(sprite)
{

  
}

ClientTile::~ClientTile()
{


  
}
void ClientTile::Draw(sf::RenderTarget* target )
{
  target->draw(this->sprite);
}

void ClientTile::SetPosition(float x, float y)
{
  this->sprite.setPosition(x,y);
  this->position = this->sprite.getPosition();
}

void ClientTile::SetSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

sf::Vector2f ClientTile::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity, sf::Vector2f direction)
{
  
  return velocity;
 
}

/**
 * 
 * 
 *  Spikes
 * 
 */

Spikes::Spikes(sf::Sprite sprite) : ClientTile(sprite)
{
}

 sf::Vector2f Spikes::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction)
{

  //sf::IntRect hitbox = this->sprite.getTextureRect();
  //
  //hitbox.top = this->sprite.getPosition().y;
  //hitbox.left = this->sprite.getPosition().x;
  //  sf::Vector2f newvel;
  //  newvel.x = velocity.x / 10;
  //  newvel.y = velocity.y / 10;
  //   
  //bool intercepts = collisionBox.intersects( hitbox );
  //
  //if (intercepts){

    return velocity;//newvel;

    
 /* }
  else
  {
    return velocity;
  }*/
  
}

Spikes::~Spikes()
{
  
}
/**
 * 
 * 
 *  floor
 * 
 */

Floor::Floor(sf::Sprite sprite) : ClientTile(sprite)
{
 
}

sf::Vector2f Floor::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction)
{

  return velocity;
}
Floor::~Floor()
{
  
}

/**
 * 
 * 
 *  Spikes
 * 
 */


Wall::Wall(sf::Sprite sprite)  : ClientTile(sprite)
{
  
}


Wall::~Wall()
{
}

sf::Vector2f Wall::DetectCollision(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction)
{
    // Wall Collision Detection is done elsewhere and not called per tile.
 




    return velocity;
}


float ClientTile::GetHorizontalIntersectionDepth(sf::IntRect rectA, sf::IntRect rectB)
	{
		// Calculate half sizes.
		float halfWidthA = rectA.width / 2.0f;
		float halfWidthB = rectB.width / 2.0f;

		// Calculate centers.
		float centerA = rectA.left + halfWidthA;
		float centerB = rectB.left + halfWidthB;

		// Calculate current and minimum-non-intersecting distances between centers.
		float distanceX = centerA - centerB;
		float minDistanceX = halfWidthA + halfWidthB;

		// If we are not intersecting at all, return (0, 0).
		if (std::abs(distanceX) >= minDistanceX)
			return 0.0f;

		// Calculate and return intersection depths.

        float dist = minDistanceX - distanceX;
        float dist2 = -minDistanceX -distanceX;
        
		return distanceX > 0 ? dist : dist2;
	}

float ClientTile::GetVerticalIntersectionDepth(sf::IntRect rectA, sf::IntRect rectB)
	{
		// Calculate half sizes.
		float halfHeightA = rectA.height / 2.0f;
		float halfHeightB = rectB.height / 2.0f;

		// Calculate centers.
		float centerA = rectA.top + halfHeightA;
		float centerB = rectB.top + halfHeightB;

		// Calculate current and minimum-non-intersecting distances between centers.
		float distanceY = centerA - centerB;
		float minDistanceY = halfHeightA + halfHeightB;

		// If we are not intersecting at all, return (0, 0).
		if (std::abs(distanceY) >= minDistanceY)
			return 0.0f;

		// Calculate and return intersection depths.
		return distanceY > 0 ? minDistanceY - distanceY : -minDistanceY - distanceY;
        //(((rectA.height/2)+(rectB.height/2)) - ((rectA.top+(rectA.height/2)) - (rectB.top + (rectB.height/2))))
	}





sf::Vector2f ClientTile::Displacement(sf::IntRect collisionBox, sf::IntRect hitbox){

     int leftX = std::max(collisionBox.left, hitbox.left);
     int rightX = std::min(collisionBox.left + collisionBox.width, hitbox.left + hitbox.width);
     int topY = std::max(collisionBox.top, hitbox.top);    
     int bottomY = std::min(collisionBox.top + collisionBox.height, hitbox.top + hitbox.height);

     //sf::IntRect rectangle = sf::IntRect( leftX, topY, rightX-leftX, bottomY-topY );
     return  sf::Vector2f( rightX-leftX, bottomY-topY); 

}