#include <shared/MapLoader.h>

using namespace std;

MapLoader::MapLoader()
{

}

std::vector<Tile> MapLoader::ReadFile(std::string path)  {

 
 std::ifstream mapfile(path.c_str());
 string mapRow;
 std::vector<Tile> tmpVect;

 int x = 0;
 int y = 0;
 
 if(mapfile.is_open()) {
  while (!mapfile.eof()) {
	  std::getline(mapfile,mapRow);
   int i = mapRow.size();
   x = 0;
   for(int j = 0 ; j < i ; j++) {
     
    char tile = mapRow.at(j);
    Tile tempTile;
    tempTile.position = sf::Vector2f(x*32,y*32);

    switch (tile) 
    {
    case 'F':
	
     //FLOOR
     tempTile.tileType = FLOOR;
	 tmpVect.push_back(tempTile);
     break;
    case 'W':
     //WALL
     tempTile.tileType = WALL;
	 tmpVect.push_back(tempTile);
     break;
    case 'S':
     //SPIKE
     tempTile.tileType = CONTACT_DAMAGE;
	 tmpVect.push_back(tempTile);
    default:

      break;

	}
	x++;
    }
	 y++;
   }
  
  }
 
 //return new vector;
 return tmpVect;
}



bool MapLoader::TileOnFloor(Tile* tile, std::vector<Tile> mapTiles, bool isPlayer){
  // Rect1 == player/Item
  // Rect2 == mapTile
  sf::Vector2f value(0,0);
  
  std::vector<Tile>::iterator it;
  int a = mapTiles.size();

  sf::IntRect rect, rect2;
  
  rect2.width = rect2.height = 32;
  
  if(isPlayer){
    rect.width = 63;
    rect.height = 38;
  }else{
    rect = rect2;
  }

  rect.left = tile->position.x;
  rect.top = tile->position.y;

  for(it = mapTiles.begin(); it != mapTiles.end();it++) {     
    // If the map tile is collidable, and they intersect, hasHitSomething = true
    if(((*it).tileType == CONTACT_DAMAGE) || ((*it).tileType == WALL)){
        rect2.left = (*it).position.x;
        rect2.top = (*it).position.y;
        if(rect.intersects(rect2)){ return false; }
    }

  }
  return true;

}

bool MapLoader::PlayersColliding(sf::Vector2f player1Pos, sf::Vector2f player2Pos)
{
    sf::IntRect rect1;
    rect1.width = PLAYER_WIDTH;
    rect1.height = PLAYER_HEIGHT;
    sf::IntRect rect2 = rect1;
    rect1.left = player1Pos.x;
    rect1.top = player1Pos.y;
    rect2.left = player2Pos.x;
    rect2.top = player2Pos.y;

    return rect1.intersects(rect2);
}


bool MapLoader::TilesColliding(Tile tile1, sf::Vector2f tile2Pos)
{
    // TODO: Not much use with colliding against players as they should have a diff hitbox
    sf::IntRect rect1;
    rect1.width = rect1.height = 32;
    sf::IntRect rect2 = rect1;
    rect1.left = tile1.position.x;
    rect1.top = tile1.position.y;
    rect2.left = tile2Pos.x;
    rect2.top = tile2Pos.y;

    return rect1.intersects(rect2);
}

bool MapLoader::TileCollidingWithTileOfType(sf::Vector2f tilePosition, std::vector<Tile> mapTiles, TileTypes tileType, bool isPlayer){
  // Rect1 == player/Item
  // Rect2 == mapTile
  sf::Vector2f value(0,0);
  
  std::vector<Tile>::iterator it;
  int a = mapTiles.size();

  sf::IntRect rect, rect2;
  
  rect2.width = rect2.height = 32;
  
  if(isPlayer){
    rect.width = 63;
    rect.height = 38;
  }else{
    rect = rect2;
  }

  rect.left = tilePosition.x;
  rect.top = tilePosition.y;

  for(it = mapTiles.begin(); it != mapTiles.end();it++) {     
    // If the map tile is collidable, and they intersect, hasHitSomething = true
    if((*it).tileType == tileType){ 
        rect2.left = (*it).position.x;
        rect2.top = (*it).position.y;
        if(rect.intersects(rect2)){ return true; }
    }
  }

  return false;

}


int MapLoader::GetTileRelativePosition(sf::IntRect box1, sf::IntRect box2){
    
    sf::Vector2i centre1(box1.left + (box1.width/2),box1.top + (box1.height/2));
    sf::Vector2i centre2(box2.left + (box2.width/2),box2.top + (box2.height/2));

    sf::Vector2i distance(centre1.x - centre2.x, centre1.y - centre2.y);
    sf::Vector2i centreDist = distance;

    bool usingX = false;
    short dir = 0; // 1 up, 2 left, 3 bottom, 4 right.

    if(abs(distance.x) < std::abs(distance.y)){ usingX = true; }

    //if(usingX){
    //    if(centre1.x < centre2.x){ dir = 4; } else { dir = 2; } // OnRight else OnLeft
    //}else{
    //    if(centre1.y < centre2.y){ dir = 1; } else { dir = 3; } // OnTop else OnBottom
    //}

    sf::IntRect player, hitbox;
    player = box1;
    hitbox = box2;

    //
    //if ((player.left - hitbox.left  < 0) && (centreDist.x >= centreDist.y)) { dir = 4; } // on left
    //else if ((player.top-hitbox.top < 0) && (centreDist.y >= centreDist.x)) { dir = 1; }// on front
    //else if ((player.left -hitbox.left > 0) && (centreDist.x >= centreDist.y)) { dir = 2; }// on right
    //else if ((player.top-hitbox.top > 0) && (centreDist.y >= centreDist.x)) { dir = 3; }// on rear


    //if ((centre1.x - centre2.x  < 0) && (centreDist.x <= centreDist.y)) { dir = 2; } // on right
    //if ((centre1.y-centre2.y < 0) && (centreDist.y <= centreDist.x)) { dir = 1; }// on front
    //if ((centre1.x -centre2.x > 0) && (centreDist.x <= centreDist.y)) { dir = 4; }// on left
    //if ((centre1.y-centre2.y > 0) && (centreDist.y <= centreDist.x)) { dir = 3; }// on rear


    //if(centreDist.x >= centreDist.y){ // either left or right
    //    if(centre1.x - centre2.x < 0) { dir = 4; } else { dir = 2; }
    //}else{ // either top or bottom
    //    if(centre1.y - centre2.y < 0) { dir = 1; } else { dir = 3; }
    //}


        if(std::abs(centreDist.x) >= std::abs(centreDist.y)){ // either left or right
            if(centre1.x - centre2.x < 0) { 
                dir = 4; 
            } else {
                dir = 2; 
            }
        }else { // either top or bottom
            if(centre1.y - centre2.y < 0) { 
                dir = 1; 
            } else { 
                dir = 3;
            }
        }


    // Box1 on {{dir}} of Box2
    
    return dir;
}