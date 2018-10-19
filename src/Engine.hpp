#pragma once

#include <allegro5/allegro.h>

#define ENGINE_LOOP for (;;)

#define ENGINE_NONE		0x0
#define ENGINE_MOUSE_INIT	0x1
#define ENGINE_KEYBOARD_INIT	0x2

#define ENGINE_RES_SMALL	0x10
#define ENGINE_RES_MEDIUM	0x11
#define ENGINE_RES_LARGE	0x12

#define ENGINE_RES_SMALL_X	320
#define ENGINE_RES_SMALL_Y	240

#define ENGINE_RES_MEDIUM_X	720
#define ENGINE_RES_MEDIUM_Y	560

#define ENGINE_RES_LARGE_X	1024
#define ENGINE_RES_LARGE_Y	768

class Engine {
private:
	Engine();

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
public:
	static Engine& getEngine();

	Engine(Engine const&) = delete;
	void operator=(Engine const&) = delete;

	int initAllegro(int flags);
	int initAllegro(int flags, int resolution, bool windowed);

	bool readyToClose();
	void cleanAndFlip();

	void destroyEngine();
};
