#pragma once
#include "SFML\Graphics.hpp"
#include "GameState.h"

#include "Tile.h"
#include "Player.h"



class MenuState : public GameState 
{

private:

	sf::Font titleFont;
	sf::Text titleText;
	sf::Text subText;



public:
	MenuState() {}
	MenuState(sf::RenderWindow &window);
	~MenuState();

	Tile tile;


	void init();

	virtual void update(float dt, StateManager &stateManager);

	virtual void render();


};

