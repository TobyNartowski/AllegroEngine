#include "Engine.hpp"

#include <iostream>
#include <vector>

int main()
{
	if (Engine::getEngine().initAllegro(ENGINE_KEYBOARD_INIT | ENGINE_MOUSE_INIT, ENGINE_RES_LARGE, ENGINE_WINDOWED)) {
		return EXIT_FAILURE;
	}

	Drawer *drawer = Engine::getEngine().getDrawerInstance();

	Point *point = new Point(128, 128);
	std::vector<Point*> points;	

	ENGINE_LOOP {
		MouseInfo mouse = Engine::getEngine().getMouse();
		point->change(mouse.x, mouse.y);

		if (mouse.isClicked) {
			points.push_back(new Point(mouse.x, mouse.y));
		}

		drawer->drawPoints(points, new Color(255, 0, 0));
		drawer->drawPoint(point, new Color(255, 255, 255));
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
