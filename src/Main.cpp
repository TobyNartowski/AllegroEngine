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
	BoundingBox *bbox = new BoundingBox(new Point(128, 128), 64, 128);
	BoundingBox *playerBbox = new BoundingBox(player->getPosition(), player->getSize(), player->getSize());

	ENGINE_LOOP(player) {	
		drawer->drawPlayer(player);
		drawer->drawCrosshair(player);

		drawer->drawBoundingBox(bbox);
		drawer->drawBoundingBox(playerBbox);
		
		playerBbox->checkForCollisions();
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
