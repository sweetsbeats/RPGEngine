#include "PlayingState.h"
#include "GameState.h"


PlayingState::PlayingState(sf::RenderWindow &window)
{
	window_ptr = &window;

	player.init(window);

	tilemap.init( window );
	tilemap.update();

	viewIsSet = false;

	collisionBox.setSize( sf::Vector2f(32, 32) );
	collisionBox.setPosition(100, 100);
	collisionBox.setFillColor(sf::Color::Green);

	
	meme = sf::FloatRect(sf::Vector2f( 0, 0 ), sf::Vector2f( 16, 16 ));


	sf::Vector2f windowSize(window_ptr->getSize().x, window_ptr->getSize().y); 

	redBackground.setSize( windowSize );
	redBackground.setFillColor(sf::Color::Red);
	

}


void PlayingState::init()
{

	player.init(*window_ptr);


	//collisions.push_back( sf::RectangleShape(   sf::Vector2f( 16, 16 )   ));
	//collisions[0].setPosition( 100, 100 );



	//std::cout << "Collisions[0] position: " << collisions[0].getPosition().x << " " << collisions[0].getPosition().y << '\n' ;

}



void PlayingState::update(float dt, StateManager &stateManager)
{

	if (!viewIsSet)
	{
		window_ptr->setView(player.playerView);
		viewIsSet = true;
	}
		
	
	
	

	if (meme.intersects(player.rect.getGlobalBounds()) )
	{
		player.canMove = false;
	}

	
	
	

	if (player.animSprite.getPosition().x + 32 >= (tilemap.mapWidth * tilemap.TileQuadSize) /*|| player.position.x >= 300 */)
	{
		






		float displacement = player.animSprite.getPosition().x+32 - (tilemap.mapWidth*tilemap.TileQuadSize);


		player.animSprite.setPosition(sf::Vector2f((player.animSprite.getPosition().x - displacement), player.animSprite.getPosition().y));

		
		/*if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
		{
			player.animSprite.setPosition(sf::Vector2f((player.animSprite.getPosition().x - 100.f * dt), player.animSprite.getPosition().y + 100.f*dt));
		}
		else
		{
			player.animSprite.setPosition(sf::Vector2f((player.animSprite.getPosition().x - 100.f* dt), player.animSprite.getPosition().y ));
		}
	*/
	}

	player.update(dt);


}



void PlayingState::render()
{


	tilemap.render();

	player.draw();



}









PlayingState::~PlayingState()
{

	

}
