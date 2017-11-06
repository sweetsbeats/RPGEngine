#include "MenuState.h"
#include "StateManager.h"




MenuState::MenuState(sf::RenderWindow &window)
{
	window_ptr = &window;
	MenuState::init();

	//titleFont.loadFromFile("resources/font/sansation.ttf");
	
	/*titleText.setFont(titleFont);
	titleText.setFillColor(sf::Color::White);
	titleText.setString("Hello, Sailor!");
	titleText.setPosition( sf::Vector2f(   (window.getSize().x + titleText.getLocalBounds().width) /2, (window.getSize().y + titleText.getLocalBounds().height) / 2) );
	
	
	*/
	//hello = sf::Text("Hello!", titleFont, 30);
}




void MenuState::init()
{
	
	/*
	rect.setSize(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(sf::Vector2f(100, 100));

	*/



	titleFont.loadFromFile("resources/font/sansation.ttf");

	titleText.setFont(titleFont);
	titleText.setFillColor(sf::Color::White);
	titleText.setString("RPG engine");
	titleText.setCharacterSize(40);
	titleText.setPosition( sf::Vector2f(   (window_ptr->getSize().x - titleText.getLocalBounds().width) /2, (window_ptr->getSize().y - titleText.getLocalBounds().height -50 ) / 2) );


	subText = sf::Text("Press 'F' to begin", titleFont, 20);
	subText.setFillColor(sf::Color::White);
	subText.setPosition(sf::Vector2f((window_ptr->getSize().x - subText.getLocalBounds().width) / 2, (window_ptr->getSize().y - subText.getLocalBounds().height + 25 ) / 2));

	


}


void MenuState::update(float dt, StateManager &stateManager)
{	
	if (input.keyboard.isKeyPressed(sf::Keyboard::F))
	{	
		stateManager.switchState(stateManager.Playing);
		
	}
}

void MenuState::render()
{
	window_ptr->draw(titleText);
	window_ptr->draw(subText);

}






MenuState::~MenuState()
{
}
