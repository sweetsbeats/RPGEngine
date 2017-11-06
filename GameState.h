#pragma once
#include "SFML\Graphics.hpp"
#include "InputManager.h"


class StateManager;


class GameState
{
public:
	GameState();
	~GameState();

	sf::RenderWindow* window_ptr = nullptr;

	InputManager input;

	virtual void update(float dt, StateManager &stateManager) = 0;

	virtual void render() = 0;

};


