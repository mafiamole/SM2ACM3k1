#include <client/ClientMapLoader.h>

ClientMapLoader::ClientMapLoader()
{

}

std::vector<ClientTile*> ClientMapLoader::PopulateClientTileSprites(std::vector<Tile>* tiles)
{
    // TODO: this needs to be map agnostic (i.e load spike.png when the map is the colosseum, force field when future map etc)
    std::vector<ClientTile*> clientTiles;
    sf::Sprite tmpSprite;
    for(int i=0; i < tiles->size();i++){

        tmpSprite.setPosition(tiles->at(i).position); 

        switch (tiles->at(i).tileType) 
        {
            case TileTypes::FLOOR:   
                {
                    tmpSprite.setTexture( MB::Content::Load<sf::Texture>("Floor.png") );

                    Floor tmpTile(tmpSprite);
                    tmpTile.position = tiles->at(i).position;
                    tmpTile.tileType = tiles->at(i).tileType;
                 
                    clientTiles.push_back(new Floor(tmpTile));
                }
             break;
            case  TileTypes::WALL:
                {
	                tmpSprite.setTexture( MB::Content::Load<sf::Texture>("Wall.png") );
                
                    Wall tmpTile(tmpSprite);
                    tmpTile.position = tiles->at(i).position;
                    tmpTile.tileType = tiles->at(i).tileType;
                 
                    clientTiles.push_back(new Wall(tmpTile));
                }
             break;
            case TileTypes::CONTACT_DAMAGE:
                {
            	    tmpSprite.setTexture( MB::Content::Load<sf::Texture>("Spike.png") );

                    Spikes tmpTile(tmpSprite);
                    tmpTile.position = tiles->at(i).position;
                    tmpTile.tileType = tiles->at(i).tileType;
                 
                    clientTiles.push_back(new Spikes(tmpTile));
                }
            default:

             break;
	    }          
    }
    return clientTiles;
}