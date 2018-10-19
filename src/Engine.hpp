#pragma once

#include <allegro5/allegro.h>

// Config variables
#define ENGINE_NONE		0x0
#define ENGINE_MOUSE_INIT	0x1
#define ENGINE_KEYBOARD_INIT	0x2

class Engine {
private:
	Engine();

	ALLEGRO_DISPLAY *display = NULL;
public:
	static Engine& getEngine();

	Engine(Engine const&) = delete;
	void operator=(Engine const&) = delete;

	int initAllegro(int flags);
};
