#include "Engine.hpp"
#include "Logger.hpp"

#include <iostream>
#include <fstream>

Engine::Engine() {
	std::ifstream file(".banner");

	if (file.is_open()) {
		std::cout << file.rdbuf();
	}
}

Engine &Engine::getEngine() {
	static Engine instance;
	return instance;
}

void Engine::destroyEngine() {
	al_destroy_display(display);
	al_destroy_event_queue(eventQueue);
}

int Engine::initAllegro(int flags) {
	if (!al_init()) {
		Logger::getLogger().logError("Failed to initialize allegro");
		return EXIT_FAILURE;
	}

	eventQueue = al_create_event_queue();
	if (!eventQueue) {
		Logger::getLogger().logError("Failed to create event queue");
		return EXIT_FAILURE;
	} else {
		Logger::getLogger().logNormal("Event queue created");
	}

	if (flags & ENGINE_MOUSE_INIT) {
		if (!al_install_mouse()) {
			Logger::getLogger().logError("Failed to initialize mouse");
			return EXIT_FAILURE;
		} else {
			Logger::getLogger().logNormal("Mouse initialized");
		}
	}

	if (flags & ENGINE_KEYBOARD_INIT) {
		if (!al_install_keyboard()) {
			Logger::getLogger().logError("Failed to initialize keyboard");
			return EXIT_FAILURE;
		} else {
			Logger::getLogger().logNormal("Keyboard initialized");
		}
	}

	Logger::getLogger().logSuccess("Allegro library initialized properly");

	return EXIT_SUCCESS;
}

int Engine::initAllegro(int flags, int resolution, bool windowed) {
	if (initAllegro(flags)) {
		return EXIT_FAILURE;
	}

	if (!windowed) {
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	}

	switch (resolution) {
		case ENGINE_RES_SMALL:
			display = al_create_display(ENGINE_RES_SMALL_X, ENGINE_RES_SMALL_Y);
			Logger::getLogger().logNormal("Created " + std::to_string(ENGINE_RES_SMALL_X) + "x" + std::to_string(ENGINE_RES_SMALL_Y) + " display");
			break;
		case ENGINE_RES_MEDIUM:
			display = al_create_display(ENGINE_RES_MEDIUM_X, ENGINE_RES_MEDIUM_Y);
			Logger::getLogger().logNormal("Created " + std::to_string(ENGINE_RES_MEDIUM_X) + "x" + std::to_string(ENGINE_RES_MEDIUM_Y) + " display");
			break;
		case ENGINE_RES_LARGE:
			display = al_create_display(ENGINE_RES_LARGE_X, ENGINE_RES_LARGE_Y);
			Logger::getLogger().logNormal("Created " + std::to_string(ENGINE_RES_LARGE_X) + "x" + std::to_string(ENGINE_RES_LARGE_Y) + " display");
			break;
		default:
			Logger::getLogger().logError("Unresolved display resolution");
			return EXIT_FAILURE;
	}

	al_register_event_source(eventQueue, al_get_display_event_source(display));

	Logger::getLogger().logSuccess("Display created properly");

	return EXIT_SUCCESS;
}

bool Engine::readyToClose() {
	ALLEGRO_EVENT event;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 0.06);

	bool getEvent = al_wait_for_event_until(eventQueue, &event, &timeout);

	if (getEvent && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		return true;
	}

	return false;
}

void Engine::cleanAndFlip() {
	al_clear_to_color(al_map_rgb(16, 16, 16));
	al_flip_display();
}
