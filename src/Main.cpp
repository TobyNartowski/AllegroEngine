#include "Engine.hpp"

#include <iostream>
#include <vector>

int main()
{
	srand(time(NULL));

	if (Engine::getEngine().initAllegro(ENGINE_KEYBOARD_INIT | ENGINE_MOUSE_INIT, ENGINE_RES_LARGE, ENGINE_WINDOWED)) {
		return EXIT_FAILURE;
	}

	Drawer *drawer = Engine::getEngine().getDrawerInstance();
	Player *player = new Player(new Point(16, 16));

	Color *rectColor = new Color(255, 255, 255);
	std::vector<Rectangle*> rects = {
		new Rectangle(new Point(128, 168), 64, 128, rectColor),
		new Rectangle(new Point(330, 160), 128, 32, rectColor),
		new Rectangle(new Point(730, 280), 28, 240, rectColor),
		new Rectangle(new Point(128, 640), 220, 100, rectColor),
		new Rectangle(new Point(480, 480), 120, 160, rectColor),
		new Rectangle(new Point(750, 580), 104, 30, rectColor),
		new Rectangle(new Point(900, 300), 95, 85, rectColor)
	};

	ENGINE_LOOP(player) {	
		drawer->drawBackground();

		drawer->drawRectangle(rects);
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
