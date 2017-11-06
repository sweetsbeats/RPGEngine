#pragma once

#include "Entity.h"


class NPC : Entity
{
private:



public:
	NPC();
	~NPC();


	virtual void update(float dt) = 0;

	virtual void draw() = 0;



};

