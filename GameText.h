#pragma once

#include <iostream>

#include "SFML\Graphics.hpp"
#include "SFML\Graphics\Text.hpp"

class GameText
{
private:

	sf::Font gameFont;
	
	bool init();


public:
	
	GameText();
	GameText(int TextSize);
	
	
	sf::Text text;

};


