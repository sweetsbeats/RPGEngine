#pragma once

#include "Entity.h"

#include "SFML\Graphics.hpp"

class Player : public Entity
{

private:


//	std::vector<Animation>animations;

	sf::Font gameFont;
	sf::Text posX;
	sf::Text posY;

	sf::Text testText;

	Animation walkUp;
	Animation walkDown;
	Animation walkLeft;
	Animation walkRight;
	

	bool debug;

	bool viewIsSet;

	bool isWalking;

	float speed = 100;

public:
	Player();
	~Player();


	sf::View playerView;

	bool canMove;


	void init(sf::RenderWindow &window);




	//virtual void init( std::string textureName );

	virtual void update(float dt);

	virtual void draw();


	void initAnimations();
	void initPlayerView();


};

