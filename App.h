#pragma once
#include "SFML\Graphics.hpp"


#include "StateManager.h"

#include "GameState.h"
#include "MenuState.h"

class App
{
public:
	App();
	~App();

	unsigned int windowWidth = 800;
	unsigned int windowHeight = 600;

	
	sf::Clock frameTimer;


	StateManager stateManager;


	//engine window
	sf::RenderWindow window;

	void init();

	void update();

	void render();
	
	//Deals with dt; makes engine update look cleaner
	float getDeltaTime();

};

