#include "Engine.hpp"

#include <iostream>
#include <fstream>

int main()
{
	Engine::getEngine().initAllegro(ENGINE_KEYBOARD_INIT | ENGINE_MOUSE_INIT);


	return 0;
}
