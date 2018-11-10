#include "Engine.hpp"

#include <iostream>
#include <vector>

int main()
{
	if (Engine::getEngine().initAllegro(ENGINE_KEYBOARD_INIT | ENGINE_MOUSE_INIT, ENGINE_RES_LARGE, ENGINE_WINDOWED)) {
		return EXIT_FAILURE;
	}

	Drawer *drawer = Engine::getEngine().getDrawerInstance();
	Player *player = new Player(new Point(16, 16));

	ENGINE_LOOP {	
		drawer->drawPlayer(player);

		player->updatePosition();
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
