#include "Engine.hpp"

#include <allegro5/allegro.h>

int main()
{
	if (Engine::getEngine().initAllegro(ENGINE_KEYBOARD_INIT | ENGINE_MOUSE_INIT, ENGINE_RES_LARGE, true)) {
		return EXIT_FAILURE;
	}

	ENGINE_LOOP {
		if (Engine::getEngine().readyToClose()) {
			break;
		}

		Engine::getEngine().cleanAndFlip();
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
