#pragma once

#include "SFML\Graphics.hpp"
#include <vector>
#include <map>
#include <fstream>


class Tile
{

private:


	//TEXTURE LOCATIONS

	std::map<std::string, sf::Vector2i> texCoords;
	


	//INIT TEXTURE LOCATIONS
	bool initTextureLocations();



public:
	Tile() {}
	Tile( sf::RenderWindow &window );
	~Tile();

	//sf::Texture* texture;

	sf::RenderWindow* window_ptr = nullptr;
	 

	sf::VertexArray testMap;



	std::vector<char> myMap;
	std::vector<sf::VertexArray>tiles;

	int mapWidth;
	int mapHeight;

	sf::Texture textureMap;

	float TileQuadSize = 16.0f;
	float textureSize = 16.f;

	sf::VertexArray quad;	

	// 0, 128
	//16, 144
	//sf::VertexArray createQuad(sf::Vector2f position, int quadSize);

	sf::VertexArray createQuad(sf::Vector2f position, sf::Vector2i texturePos, int quadSize);

	sf::VertexArray createQuad(sf::Vector2f position, sf::Vector2i texturePos, float quadSize);

	void m_createQuad(sf::Vector2f position, sf::Vector2i texturePos, float quadSize);

	void init(sf::RenderWindow &window);



	void stuff();

	void update();

	void render();

	std::vector<char> loadMapFromFile(std::string mapName);
};

