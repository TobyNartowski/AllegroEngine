#include "Engine.hpp"
#include "LineSegment.hpp"

#include <iostream>
#include <vector>

int main()
{
	if (Engine::getEngine().initAllegro(ENGINE_KEYBOARD_INIT | ENGINE_MOUSE_INIT, ENGINE_RES_LARGE, ENGINE_WINDOWED)) {
		return EXIT_FAILURE;
	}

	Drawer *drawer = Engine::getEngine().getDrawerInstance();

	Point *point = new Point(128, 128);

	ENGINE_LOOP {
		float delta = 5.0;
		bool *keys = Engine::getEngine().getKeys();

		if (keys[KEY_UP] == true) {
			point->move(0, -delta);
		}
		
		if (keys[KEY_DOWN] == true) {
			point->move(0, delta);
		}
		
		if (keys[KEY_RIGHT] == true) {
			point->move(delta, 0);
		}
		
		if (keys[KEY_LEFT] == true) {
			point->move(-delta, 0);
		}

		drawer->drawPoint(point, new Color(255, 255, 255));
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
