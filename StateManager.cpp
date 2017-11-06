#include "StateManager.h"

StateManager::StateManager(sf::RenderWindow &window)
{
	//StateManager::init(window);

	currentGameState = Menu;
	


}

void StateManager::init(sf::RenderWindow &window)
{

//	inputManager = InputManager();

	// statemanagers' init initializes every state, and sets the state pointer to the default (menu)
		menu = MenuState(window);
	playing = PlayingState(window);



	playing.init();

	menu.init();


	state = &menu;
}


void StateManager::update(float dt)
{

	if (currentGameState == Transitioning)
		StateManager::setState();

	state->update(dt, *this);

}



void StateManager::render()
{
	state->render();
}


void StateManager::switchState(GameStates newState)
{
	if (currentGameState != newState )
	{
		currentGameState = Transitioning;
		transitionState = newState;
		//TODO: CALL A STATE'S TRANSITION CODE
	}
	//				call transition code of 
	

}



void StateManager::setState()
{
	switch (transitionState)
	{
	case StateManager::Menu:
		//menu.transition();
		currentGameState = Menu;
		state = &menu;

		break;
	case StateManager::Playing:

		//playing.transition();
		currentGameState = Playing;
		state = &playing;
		


		break;
	case StateManager::Transitioning:
		break;

	}

}



StateManager::~StateManager()
{
}



