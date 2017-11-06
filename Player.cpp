#include "Player.h"
#include <iostream>


Player::Player()
{
}


Player::~Player()
{
}


void Player::init(sf::RenderWindow &window)
{

//	AnimatedSprite animSprite;
	animSprite.setPosition( sf::Vector2f(200, 200) );
	currentAnimation = &walkDown;

	texture.loadFromFile("resources/textures/Player.png");
	
	//call player animations initializations
	Player::initAnimations();
		
	window_ptr = &window;

	//init out player options
	initPlayerView();

	


	debug = false;

	isWalking = false;

	canMove = true;

	viewIsSet = false;

	gameFont.loadFromFile("resources/font/sansation.ttf");

	posX.setCharacterSize(20);
	posY.setCharacterSize(20);

	posX.setFont(gameFont);
	posY.setFont(gameFont);

	//posX.setPosition( sf::Vector2f(  animSprite.getPosition().x - 100, animSprite.getPosition().y - 100) );
	//posY.setPosition(sf::Vector2f(animSprite.getPosition().x - 100, animSprite.getPosition().y - 100) );
	
	posX.setFillColor(sf::Color::Red);
	posY.setFillColor(sf::Color::Red);

}


void Player::update(float dt)
{
	//get frameTime to appease the animatedSprite's update
	sf::Time frameTime = frameClock.restart();

	//				ADD STUFF HERE



	if (!viewIsSet)
	{
		window_ptr->setView(playerView);
		viewIsSet = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && debug == false )
		debug = true;
		

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::PageUp ) )
	{
		playerView.zoom(0.99f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
	{
		playerView.zoom(1.01f);
	}
	



	// reset velocity on update
	sf::Vector2f velocity(0, 0);

	if (canMove)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)  )
		{
			currentAnimation = &walkUp;
			velocity.y -= (speed * dt);
			isWalking = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)  )
		{
			currentAnimation = &walkDown;
			velocity.y += (speed * dt);
			isWalking = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)  )
		{
			currentAnimation = &walkLeft;
			velocity.x -= (speed * dt);
			isWalking = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)  )
		{
				currentAnimation = &walkRight;
				velocity.x += (speed * dt);
				isWalking = true;
		}



	}

	//Normalize vector
	if (velocity.x != 0.0f && velocity.y != 0.0f)
	{ velocity /= sqrt(2.0f); }





	//				STOP ADDING STUFF HERE

	animSprite.play( *currentAnimation );

	//apply velocity 
	animSprite.move(velocity);
	


	//keep playerView on player pos

//	playerView.setCenter(animSprite.getPosition());

	playerView.setCenter(animSprite.getPosition());


	//if not moving, stop animations
	if (!isWalking)
	{ animSprite.stop(); }

	//Reset walking bool; If player stops moving next update, code above catches it
	isWalking = false;

	animSprite.update(frameTime);



	
	if (debug == true)
	{
		posX.setPosition(sf::Vector2f(animSprite.getPosition().x - 290, animSprite.getPosition().y - 200));
		posY.setPosition(sf::Vector2f(animSprite.getPosition().x - 290, animSprite.getPosition().y - 175));

		posX.setString(std::to_string((int)animSprite.getPosition().x));
		posY.setString(std::to_string((int)animSprite.getPosition().y));
		//std::cout << "("<< animSprite.getPosition().x << ", " << animSprite.getPosition().y << ")" << '\n';
	}
}


void Player::draw()
{
	window_ptr->draw(animSprite);
	if (debug == true)
	{
		window_ptr->draw(posX);
		window_ptr->draw(posY);
	}

}




void Player::initPlayerView()
{
	playerView.setSize(sf::Vector2f(600, 400));
	playerView.zoom(1);
	playerView.setCenter(animSprite.getPosition());
}



void Player::initAnimations()
{
	//give animations the spritesheet

	//TODO: Come up with cleaner way to hold animations, maybe a vector

	walkUp.setSpriteSheet(texture);
	walkDown.setSpriteSheet(texture);
	walkLeft.setSpriteSheet(texture);
	walkRight.setSpriteSheet(texture);


	

	//Add walkUp frames
	walkUp.addFrame(sf::IntRect(32, 96, 32, 32));
	walkUp.addFrame(sf::IntRect(64, 96, 32, 32));
	walkUp.addFrame(sf::IntRect(32, 96, 32, 32));
	walkUp.addFrame(sf::IntRect(0, 96, 32, 32));

	//Add walkDown frames
	walkDown.addFrame(sf::IntRect(32, 0, 32, 32));
	walkDown.addFrame(sf::IntRect(64, 0, 32, 32));
	walkDown.addFrame(sf::IntRect(32, 0, 32, 32));
	walkDown.addFrame(sf::IntRect(0, 0, 32, 32));


	//Add walkLeft frames
	walkLeft.addFrame(sf::IntRect(32, 32, 32, 32));
	walkLeft.addFrame(sf::IntRect(64, 32, 32, 32));
	walkLeft.addFrame(sf::IntRect(32, 32, 32, 32));
	walkLeft.addFrame(sf::IntRect(0, 32, 32, 32));

	//Add walkRight frames
	walkRight.addFrame(sf::IntRect(32, 64, 32, 32));
	walkRight.addFrame(sf::IntRect(64, 64, 32, 32));
	walkRight.addFrame(sf::IntRect(32, 64, 32, 32));
	walkRight.addFrame(sf::IntRect(0, 64, 32, 32));

}






