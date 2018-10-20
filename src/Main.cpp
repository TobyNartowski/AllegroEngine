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

	std::vector<LineSegment*> lines = {
		new LineSegment(new Point(512, 512), new Point(512, 384)),
		new LineSegment(new Point(512, 384), new Point(600, 355))
	};

	ENGINE_LOOP {
		drawer->fillBackground(new Color(16, 16, 16));
	
		drawer->drawRectangle(new Point(64, 64), new Point(256, 256), new Color(255, 255, 255), 10);
		drawer->drawTriangle(new Point(512, 600), new Point(640, 640), new Point(480, 640), new Color(255, 0, 0), 10);
		drawer->drawEllipse(new Point(512, 128), 32, 32, new Color(0, 255, 0), 10);

		drawer->drawMultipleLines(lines, new Color(255, 255, 255));
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
