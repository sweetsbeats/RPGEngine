#pragma once
#include "SFML\Graphics.hpp"

#include "InputManager.h"

#include "GameState.h"
#include "MenuState.h"
#include "PlayingState.h"

class StateManager
{

private:

	//All Major gamestate objects get defined here
	MenuState menu;
	PlayingState playing;

public:
	StateManager() {}
	StateManager(sf::RenderWindow &window);
	~StateManager();



	//Keep track of the games major states
	enum GameStates
	{
		Menu,
		Playing,
		Transitioning
	};

	GameStates currentGameState;
	GameStates transitionState;

	GameState* state = nullptr;



	void init(sf::RenderWindow &window);

	void update(float dt);

	void render();

	void switchState(GameStates newState);

	void setState();


};


