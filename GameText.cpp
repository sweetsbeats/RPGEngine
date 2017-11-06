#include "GameText.h"


GameText::GameText()
{
	if (!init())
	{
		std::cout << sf::err << '\n';
	}
}


GameText::GameText(int TextSize)
{
	if (!init())
	{
		std::cout << sf::err << '\n';
	}

	text.setCharacterSize(TextSize);


	

}


bool GameText::init()
{

	sf::Font gameFont;
	gameFont.loadFromFile("resources/font/sansation.ttf");
	text.setFont(gameFont);
	
	text.setFillColor(sf::Color::White);
	


	return true;
}

