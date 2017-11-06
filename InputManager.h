#pragma once
#include "SFML/Graphics.hpp"
class InputManager
{

public:
	InputManager();
	~InputManager();


	enum inputType
	{
		W,
		A,
		S,
		D
	};


	inputType currentInput;

	sf::Keyboard keyboard;

	InputManager::inputType getInputs();

	void processInputs();

	
private:



};

