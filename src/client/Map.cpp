#include "client/Map.h"
#include <iostream>

Map::Map(sf::RenderTarget* renderTarget, std::vector<ClientTile*> tileList){
	tiles = tileList;
	rendTarget = renderTarget;
}
Map::Map(){
  
}

void Map::Draw() {
  
	std::vector<ClientTile*>::iterator it;
	int a = tiles.size();

	for(it = tiles.begin(); it != tiles.end();it++) {
	  
	  (*it)->Draw(this->rendTarget);
		
	}

}


sf::Vector2f Map::collisionDetect(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction) {

  sf::Vector2f value(0,0), newValue(0,0);
  sf::IntRect originalRect = collisionBox;
  collisionBox.top += velocity.y;
  collisionBox.left += velocity.x;

  std::vector<ClientTile*>::iterator it;


  if(velocity == value){ return velocity; }  // value being 0,0 atm. Might still be desirable to process collisions even if not moving though... possible TODO: 


  // Do a wall check outside of loop, as it will call the loop within itself anyway.
  newValue = WallCheck(originalRect,velocity,direction);
  

  for(it = tiles.begin(); it != tiles.end();it++) {
    ClientTile* tile = (*it);
    
    switch(tile->tileType){
    case FLOOR: // No action for floors, don't even bother checking collision
            
        break;
    case WALL: // Any extra processing (not collision) for walls
       
        break;
    default: // do a standard bounding box collision check for anything else (only spikes I think atm)
        value = tile->DetectCollision(collisionBox, velocity,direction);

          
    }// end case   
  }

   if (newValue != velocity)
    {
        return newValue;      
    }

  return velocity;
  
}



sf::Vector2f Map::WallCheck(sf::IntRect collisionBox, sf::Vector2f velocity,sf::Vector2f direction){
     sf::IntRect origBox = collisionBox;
     sf::IntRect fullCollBox = collisionBox;
     fullCollBox.top += velocity.y;
     fullCollBox.left += velocity.x;
     sf::IntRect hitbox;

     std::vector<ClientTile*>::iterator it;

    
     sf::Vector2f depth = sf::Vector2f(0,0);

        // Deal with horizontal collision
        
         for(it = tiles.begin(); it != tiles.end();it++) {
                ClientTile* tile = (*it);
                
                if(tile->tileType == WALL){

                    if(velocity.x != 0){  
               
                        if(direction.x > 0){
                            collisionBox.left = fullCollBox.left = origBox.left + velocity.x - depth.x;
                        }
                        if(direction.x < 0){                    
                            collisionBox.left = fullCollBox.left = origBox.left + velocity.x + depth.x;
                        }

                        hitbox = sf::IntRect(tile->position.x, tile->position.y, 32, 32);
                        if(!fullCollBox.intersects(hitbox)){ continue; }; // if this tile not intersecting at all, might as well skip to next tile.
        
                        depth.x = tile->Displacement(collisionBox,hitbox).x;                
   
                    }
                }
        }
        

        // Reset the collision boxes
        fullCollBox = collisionBox = origBox;

        // Deal with vertical collision
        if(velocity.y != 0){            
            for(it = tiles.begin(); it != tiles.end();it++) {      
                ClientTile* tile = (*it);
                
                if(tile->tileType == WALL){

                if(direction.y > 0){
                    collisionBox.top = fullCollBox.top = origBox.top + velocity.y - depth.y;
                }
                if(direction.y < 0){                    
                    collisionBox.top = fullCollBox.top = origBox.top + velocity.y + depth.y;
                }                
                

                hitbox = sf::IntRect(tile->position.x, tile->position.y, 32, 32);
                if(!fullCollBox.intersects(hitbox)){ continue; } // if this tile not intersecting at all, might as well skip to next tile.

                depth.y = tile->Displacement(collisionBox,hitbox).y;
                                        
                // if diagonal, if next move is still collidng, cancel movement.
                if(direction.x != 0 && direction.y != 0){
                    if(direction.y > 0){
                        collisionBox.top = fullCollBox.top = origBox.top + velocity.y - depth.y;
                    }
                    if(direction.y < 0){                    
                        collisionBox.top = fullCollBox.top = origBox.top + velocity.y + depth.y;
                    }                  

                    if(tile->Displacement(collisionBox,hitbox).y == 0){
                                depth.x = 0;
                    }
                }
                
                }
            }
        }

        if(depth != sf::Vector2f(0,0) ){
            
            if(depth.x != 0){
                if(direction.x < 0){
                    depth.x = velocity.x + depth.x;
                }
                if(direction.x > 0){
                    depth.x = velocity.x + (depth.x*-1);  
                }               
               
            }
            if(depth.y != 0){
                if(direction.y < 0){
                    depth.y = velocity.y + depth.y; 
                }
                if(direction.y > 0){
                    depth.y = velocity.y + (depth.y*-1); 
                }
            }




             return depth; 
        } 
        return velocity;

}
