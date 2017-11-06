#pragma once
#include "SFML\Graphics.hpp"

#include "Animation.h"
#include "AnimatedSprite.h"


class Entity
{
public:
	Entity();
	~Entity();


	sf::RenderWindow* window_ptr = nullptr;

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f position;

	sf::Clock frameClock;

	Animation* currentAnimation = nullptr;
	AnimatedSprite animSprite;

	sf::RectangleShape rect;


	//virtual void init( std::string textureName ) = 0;

	virtual void update(float dt) = 0;

	virtual void draw() = 0;



};

