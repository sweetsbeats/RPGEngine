#include "App.h"

App::App()
{
	//App::init();	

	//initialize our window

	//StateManager stateManager(window);


}


void App::init()
{
	
	//initialize our window
	window.create(sf::VideoMode(windowWidth, windowHeight), "Engine");

	window.setFramerateLimit(60);
	
	stateManager.init(window);


}

void App::update()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// if window doesn't have focus, game loop will freeze
		if (window.hasFocus())

		{
			//get out deltaTime
			float dt = frameTimer.getElapsedTime().asSeconds();
			frameTimer.restart();

			//Call on stateManager to handle updates
			stateManager.update(dt);


			//Rendering is contained in App and inside  "App.update()"  (gameloop)
			window.clear();
			App::render();
			window.display();
		}
	}
}





void App::render()
{
	//calls on stateManagers internal pointer to current state to render
	stateManager.render();
}



float App::getDeltaTime()
{
	float deltaTime;
	deltaTime = frameTimer.getElapsedTime().asSeconds();
	frameTimer.restart();

	return deltaTime;
	
}



//nobody cares about this fucker
App::~App()
{
}