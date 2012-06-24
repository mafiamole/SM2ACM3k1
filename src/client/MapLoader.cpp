#include <client/MapLoader.h>

using namespace std;

MapLoader::MapLoader()
{

}


std::vector<sf::Sprite> MapLoader::ReadFile(std::string path)  {

	sf::Texture wallTexture;
	sf::Texture floorTexture;
	sf::Texture spikeTexture;
	

 std::ifstream mapfile(path.c_str());
 string mapRow;
 std::vector<sf::Sprite> tmpVect;

 int x = 0;
 int y = 0;

 
 if(mapfile.is_open()) {
  while (!mapfile.eof()) {
	  std::getline(mapfile,mapRow);

   int i = mapRow.size();
   x = 0;
   for(int j = 0 ; j < i ; j++) {
    char tile = mapRow.at(j);
	sf::Sprite tmpSprite;
    switch (tile) {
    case 'F':
	{
     //FLOOR
		tmpSprite = sf::Sprite(MB::Content::Load<sf::Texture>("Floor.png"));		
     break;
	}
    case 'W':
	{
     //WALL
		tmpSprite = sf::Sprite( MB::Content::Load<sf::Texture>("Wall.png"));
     break;
	}
    case 'S':
	{
     //SPIKE
		tmpSprite = sf::Sprite(MB::Content::Load<sf::Texture>("Spike.png"));
	default:
		break;
	}
    }
	tmpSprite.setPosition(x*32, y*32);
	tmpVect.push_back(tmpSprite);
	x++;
   }
   y++;
  }
 }

 //return new vector;
 return tmpVect;
}