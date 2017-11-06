#include "Tile.h"

#include <iostream>
#include "SFML\OpenGL.hpp"

#include "SFML\Graphics.hpp"
#include "SFML\Main.hpp"

Tile::Tile( sf::RenderWindow &window )


{

	window_ptr = &window;

	//Tile::init();


}


Tile::~Tile()
{
}



//
//							TODO:
//					- collision mapping 
//
//		Push 
//
//							




void Tile::init( sf::RenderWindow &window )
{
	
	window_ptr = &window;

	textureMap.loadFromFile("resources/tilemap/zelda.png");


	if (initTextureLocations())
	{
		std::cout << "Texture coordinates were successfully initialized! \n";
	}
	else
	{
		std::cout << "Texture coordinates failed to initialize!";
		sf::err();
	}

	testMap.setPrimitiveType(sf::Quads);
	
	
}



bool Tile::initTextureLocations()
{
	texCoords["grass"] = sf::Vector2i(0, 128);
	texCoords["flower"] = sf::Vector2i(48, 64);

		return true;
}




void Tile::stuff()
{

}





void Tile::update()
{




	myMap = loadMapFromFile("resources/tilemap/map.txt");
	std::cout << mapWidth << "\n" << mapHeight << "\n";


	int myX = 0;
	int myY = 0;

	for (int i = 0; i < myMap.size(); i++)
	{
		if (myX == mapWidth)
		{
			myY++;
		}

		if (myX == mapWidth)
		{
			myX = 0;
		}

		switch (myMap[i])
		{
		case '0':

			

			break;

		case '1':
			
			//tiles.push_back(createQuad(sf::Vector2f((16.f * myX), (16.f * myY)), texCoords["grass"], TileQuadSize));
			

			m_createQuad(sf::Vector2f((16.f * myX), (16.f * myY)), texCoords["grass"], TileQuadSize);

			break;

		case '2':

			m_createQuad(sf::Vector2f((16.f * myX), (16.f * myY)), texCoords["flower"], TileQuadSize);

			//tiles.push_back(createQuad(sf::Vector2f((16.f * myX), (16.f * myY)), texCoords["flower"], TileQuadSize));

			break;
		}


		myX++;

	}


}


/*void Tile::otherStuff()
{

	myMap = loadMapFromFile("resources/tilemap/map.txt");
	std::cout << mapWidth << "\n" << mapHeight << "\n";

	std::cout << "Size of myMap is: " << myMap.size() << '\n' ;
	
	int myX = 0;
	int myY = 0;

	for (int i = 0; i < myMap.size(); i++)
	{				
		if (myX == mapWidth)
		{
			myY++;
		}
				
		if (myX == mapWidth)
		{
			myX = 0;
		}
		
			switch (myMap[i])
			{
			case '0':

				std::cout << "0";

				break;

			case '1':
				std::cout << "1";
				tiles.push_back(createQuad(sf::Vector2f(0 + (16 * myX), 0 + (16 * myY)), texCoords["grass"], 16));
				break;

			case '2':
				
				std::cout << "2";

				tiles.push_back(createQuad(sf::Vector2f(0 + (16 * myX), 0 + (16 * myY)), texCoords["flower"], 16));

				break;
			}
		

			myX++;
		
	}
	
	/*for (int x = 0; x < 32; x++)
	{
		for (int y = 0; y < 32; y++)
		{
			//Access array inverted in order to draw it correctly
			switch (tilemaps[y][x])
			{
			case 0:
				tiles.push_back(createQuad(sf::Vector2f(0 + (16 * x), 0 + (16 * y)), texCoords["flower"], 16));
				break;
			case 1:
				tiles.push_back(createQuad(sf::Vector2f(0 + (16 * x), 0 + (16 * y)), texCoords["grass"], 16));
				break;
			}
		}
	}


}*/




void Tile::render()
{
	/*for ( int i=0; i < tiles.size(); i++ )
	{
		window_ptr->draw( tiles[i], &textureMap );
	}
	*/
	window_ptr->draw(testMap, &textureMap);
	



}

//sf::Vector2f(      0 + (16 * x), 0 + (16 * myY)           )

sf::VertexArray Tile::createQuad(sf::Vector2f position, sf::Vector2i texturePos, int quadSize)
{
	sf::VertexArray quad(sf::Quads, 4);

	quad[0] = position;
	quad[1] = sf::Vector2f(position.x + quadSize, position.y);
	quad[2] = sf::Vector2f(position.x + quadSize, position.y + quadSize);
	quad[3] = sf::Vector2f(position.x, position.y + quadSize);

	for (int i = 0; i < quad.getVertexCount(); i++)
	{
		//quad[i].color = sf::Color::Red;

		quad[0].texCoords = sf::Vector2f( texturePos.x, texturePos.y );
		quad[1].texCoords = sf::Vector2f( texturePos.x + quadSize, texturePos.y );
		quad[2].texCoords = sf::Vector2f( texturePos.x + quadSize, texturePos.y + quadSize );
		quad[3].texCoords = sf::Vector2f( texturePos.x, texturePos.y + quadSize );

	}

	return quad;
}


sf::VertexArray Tile::createQuad(sf::Vector2f position, sf ::Vector2i texturePos, float quadSize)
{
	sf::VertexArray quad(sf::Quads, 4);

	quad[0] = position;
	quad[1] = sf::Vector2f(position.x + quadSize, position.y);
	quad[2] = sf::Vector2f(position.x + quadSize, position.y + quadSize);
	quad[3] = sf::Vector2f(position.x, position.y + quadSize);

	for (int i = 0; i < quad.getVertexCount(); i++)
	{
		//quad[i].color = sf::Color::Red;

		quad[0].texCoords = sf::Vector2f(texturePos.x, texturePos.y);
		quad[1].texCoords = sf::Vector2f(texturePos.x + quadSize, texturePos.y);
		quad[2].texCoords = sf::Vector2f(texturePos.x + quadSize, texturePos.y + quadSize);
		quad[3].texCoords = sf::Vector2f(texturePos.x, texturePos.y + quadSize);

	}

	return quad;
}





void Tile::m_createQuad(sf::Vector2f position, sf::Vector2i texturePos, float quadSize)
{


	testMap.append(sf::Vertex(position, sf::Vector2f(texturePos.x, texturePos.y)));

	testMap.append(sf::Vertex(sf::Vector2f(position.x + quadSize, position.y), sf::Vector2f(texturePos.x + textureSize, texturePos.y)));

	testMap.append(sf::Vertex(sf::Vector2f(position.x + quadSize, position.y + quadSize), sf::Vector2f(texturePos.x + textureSize, texturePos.y + textureSize)));

	testMap.append(sf::Vertex(sf::Vector2f(position.x, position.y + quadSize), sf::Vector2f(texturePos.x, texturePos.y + textureSize)));
	
}





std::vector<char> Tile::loadMapFromFile(std::string mapName)
{

	std::vector<char>map;
	std::ifstream mapfile;
	
	mapfile.open(mapName);

	char widthBuffer[256];
	char heightBuffer[256];

	mapfile.getline( widthBuffer, 4 );
	std::cout << "Got width! It's: " << widthBuffer << "\n";

	mapfile.getline( heightBuffer, 4 );
	std::cout << "Got height! It's: " << heightBuffer << "\n";

	//		return size to class memebers
	mapWidth = atoi( widthBuffer );
	mapHeight = atoi(heightBuffer);
	//store internals to please char array

	int w = atoi(widthBuffer) + 1;
	int h = atoi(heightBuffer);

	//Dynamically allocated mapBuffer using the heap. *Shudders*
	char* mapBuffer = new char[w*h];
	
	//read map data 
	mapfile.read(mapBuffer, (w*h) );

	std::cout << "successfully Loaded map data! \n";
	
	//Parse char array for actual data, then push it to vector
	for (int i = 0; i < (w*h); i++)
	{
		if (mapBuffer[i] != '\n')
		{
			map.push_back(mapBuffer[i]);
		}
	}

	mapfile.close();

	delete[] mapBuffer;

	return map;	
}





