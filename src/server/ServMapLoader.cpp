#include <server/ServMapLoader.h>

using namespace std;

ServMapLoader::ServMapLoader()
{

}

std::vector<ServTile> ServMapLoader::ReadFile(std::string path)  {

 
 std::ifstream mapfile(path.c_str());
 string mapRow;
 std::vector<ServTile> tmpVect;

 int x = 0;
 int y = 0;
 
 if(mapfile.is_open()) {
  while (!mapfile.eof()) {
	  std::getline(mapfile,mapRow);
   int i = mapRow.size();
   x = 0;
   for(int j = 0 ; j < i ; j++) {
     
    char tile = mapRow.at(j);
    ServTile tempTile;
    tempTile.position = sf::Vector2f(x*32,y*32);

    switch (tile) 
    {
    case 'F':
	
     //FLOOR
     tempTile.tileType = TileTypes::FLOOR;
	 tmpVect.push_back(tempTile);
     break;
    case 'W':
     //WALL
     tempTile.tileType = TileTypes::WALL;
	 tmpVect.push_back(tempTile);
     break;
    case 'S':
     //SPIKE
     tempTile.tileType = TileTypes::CONTACT_DAMAGE;
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



bool ServMapLoader::TileOnFloor(ServTile* tile, std::vector<ServTile> mapTiles, bool isPlayer){
  // Rect1 == player/Item
  // Rect2 == mapTile
  sf::Vector2f value(0,0);
  
  std::vector<ServTile>::iterator it;
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
    if(((*it).tileType == TileTypes::CONTACT_DAMAGE) || ((*it).tileType == TileTypes::WALL)){
        rect2.left = (*it).position.x;
        rect2.top = (*it).position.y;
        if(rect.intersects(rect2)){ return false; }
    }

  }
  return true;

}

bool ServMapLoader::PlayersColliding(sf::Vector2f player1Pos, sf::Vector2f player2Pos)
{
    sf::IntRect rect1;
    rect1.width = 63;
    rect1.height = 38;
    sf::IntRect rect2 = rect1;
    rect1.left = player1Pos.x;
    rect1.top = player1Pos.y;
    rect2.left = player2Pos.x;
    rect2.top = player2Pos.y;

    return rect1.intersects(rect2);
}


bool ServMapLoader::TilesColliding(ServTile* tile1, sf::Vector2f tile2Pos)
{
    // TODO: Not much use with colliding against players as they should have a diff hitbox
    sf::IntRect rect1;
    rect1.width = rect1.height = 32;
    sf::IntRect rect2 = rect1;
    rect1.left = tile1->position.x;
    rect1.top = tile1->position.y;
    rect2.left = tile2Pos.x;
    rect2.top = tile2Pos.y;

    return rect1.intersects(rect2);
}