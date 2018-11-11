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

	std::vector<Rectangle*> rects = {
		new Rectangle(new Point(128, 128), 64, 128, new Color(255, 255, 255)),
		new Rectangle(new Point(330, 160), 128, 32, new Color(255, 255, 255)),
		new Rectangle(new Point(730, 280), 28, 240, new Color(255, 255, 255)),
		new Rectangle(new Point(128, 640), 220, 100, new Color(255, 255, 255)),
		new Rectangle(new Point(480, 480), 120, 160, new Color(255, 255, 255)),
		new Rectangle(new Point(750, 580), 104, 30, new Color(255, 255, 255))
	};

	new Enemy(new Point(600, 600));

	ENGINE_LOOP(player) {	
		drawer->drawRectangle(rects);
	}

	Engine::getEngine().destroyEngine();

	return EXIT_SUCCESS;
}
