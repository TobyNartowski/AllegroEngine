#include "Engine.hpp"

#include <iostream>
#include <vector>

int main()
{
	if (Engine::getEngine().initAllegro(ENGINE_KEYBOARD_INIT | ENGINE_MOUSE_INIT, ENGINE_RES_LARGE, ENGINE_WINDOWED)) {
		return EXIT_FAILURE;
	}

	Drawer *drawer = Engine::getEngine().getDrawerInstance();

	std::vector<Point*> points = {new Point(12, 16), new Point(16, 18), new Point(20, 24)};
	

	ENGINE_LOOP {
		drawer->fillBackground(new Color(16, 16, 16));
		drawer->drawPoints(points, new Color(255, 255, 255));
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
