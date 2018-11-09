#include "Engine.hpp"

#include <iostream>
#include <vector>

int main()
{
	if (Engine::getEngine().initAllegro(ENGINE_KEYBOARD_INIT | ENGINE_MOUSE_INIT, ENGINE_RES_LARGE, ENGINE_WINDOWED)) {
		return EXIT_FAILURE;
	}

	Drawer *drawer = Engine::getEngine().getDrawerInstance();

	Viewport *viewport = new Viewport(new Point(128, 128), new Point(400, 312));
	std::vector<LineSegment*> lines = {
		new LineSegment(new Point(60, 60), new Point(300, 300)),
		new LineSegment(new Point(300, 300), new Point(100, 400)),
		new LineSegment(new Point(100, 400), new Point(800, 500))
	};

	ENGINE_LOOP {
		float delta = 5.0;
		bool *keys = Engine::getEngine().getKeys();

		if (keys[KEY_UP] == true) {
			viewport->move(0, -delta);
		}
		
		if (keys[KEY_DOWN] == true) {
			viewport->move(0, delta);
		}
		
		if (keys[KEY_RIGHT] == true) {
			viewport->move(delta, 0);
		}
		
		if (keys[KEY_LEFT] == true) {
			viewport->move(-delta, 0);
		}

		drawer->drawMultipleLines(viewport->clip(lines), new Color(255, 255, 255));

		drawer->drawViewport(viewport, new Color(255, 0, 0));
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
