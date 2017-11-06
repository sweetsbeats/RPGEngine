#include "InputManager.h"



InputManager::InputManager()
{
	currentInput = S;
}




InputManager::inputType InputManager::getInputs()
{
	if (keyboard.isKeyPressed(keyboard.Left))
	{ return A; }

	if (keyboard.isKeyPressed(keyboard.Right))
	{ return D; }

	if (keyboard.isKeyPressed(keyboard.Up))
	{ return W; }

	if (keyboard.isKeyPressed(keyboard.Down))
	{ return S; }	
}




void InputManager::processInputs()
{
	//get input
	currentInput = getInputs();




}





InputManager::~InputManager()
{
}
