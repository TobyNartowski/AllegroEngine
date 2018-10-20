#include "Engine.hpp"

#include <iostream>

int main()
{
	if (Engine::getEngine().initAllegro(ENGINE_KEYBOARD_INIT | ENGINE_MOUSE_INIT, ENGINE_RES_LARGE, true)) {
		return EXIT_FAILURE;
	}

	ENGINE_LOOP {

	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
