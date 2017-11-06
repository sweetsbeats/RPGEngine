#pragma once
#include "GameState.h"
#include "Player.h"

#include "Tile.h"
#include <iostream>


class PlayingState : public GameState
{


private:

	bool viewIsSet;

	sf::RectangleShape collisionRectangleColour;

	Player player;

	Tile tilemap;



	//std::vector<sf::RectangleShape>collisions;

	sf::FloatRect meme;
	sf::RectangleShape collisionBox;

	sf::RectangleShape redBackground;


public:
	PlayingState() {}
	PlayingState(sf::RenderWindow &window);
	~PlayingState();


	void init();

	virtual void update(float dt, StateManager &stateManager);

	virtual void render();

};

