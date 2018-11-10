#include "Engine.hpp"
#include "Logger.hpp"

#include <fstream>
#include <allegro5/allegro_native_dialog.h>

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
	al_destroy_timer(timer);
	Logger::getLogger().logNormal("Memory cleaned up");
}

int Engine::initAllegro(int flags) {
	if (!al_init()) {
		Logger::getLogger().logError("Failed to initialize Allegro");
		showError("Failed to initialize Allegro");
		return EXIT_FAILURE;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		Logger::getLogger().logError("Failed to create timer");
		showError("Failed to create timer");
		return EXIT_FAILURE;
	}

	eventQueue = al_create_event_queue();
	if (!eventQueue) {
		Logger::getLogger().logError("Failed to create event queue");
		showError("Failed to create event queue");
		return EXIT_FAILURE;
	} else {
		Logger::getLogger().logNormal("Event queue created");
	}

	if (flags & ENGINE_MOUSE_INIT) {
		if (!al_install_mouse()) {
			Logger::getLogger().logError("Failed to initialize mouse");
			showError("Failed to initialize mouse");
			return EXIT_FAILURE;
		} else {
			Logger::getLogger().logNormal("Mouse initialized");
		}
	}

	if (flags & ENGINE_KEYBOARD_INIT) {
		if (!al_install_keyboard()) {
			Logger::getLogger().logError("Failed to initialize keyboard");
			showError("Failed to initialize keyboard");
			return EXIT_FAILURE;
		} else {
			Logger::getLogger().logNormal("Keyboard initialized");
		}
	}

	Logger::getLogger().logSuccess("Allegro library initialized properly");

	drawer = new Drawer(display);

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
			bbox = new BoundingBox(new Point(ENGINE_RES_SMALL_X / 2.0, ENGINE_RES_SMALL_Y / 2.0), ENGINE_RES_SMALL_X - 16.0, ENGINE_RES_SMALL_Y - 16.0, INVERTED);
			break;
		case ENGINE_RES_MEDIUM:
			display = al_create_display(ENGINE_RES_MEDIUM_X, ENGINE_RES_MEDIUM_Y);
			Logger::getLogger().logNormal("Created " + std::to_string(ENGINE_RES_MEDIUM_X) + "x" + std::to_string(ENGINE_RES_MEDIUM_Y) + " display");
			bbox = new BoundingBox(new Point(ENGINE_RES_MEDIUM_X / 2.0, ENGINE_RES_MEDIUM_Y / 2.0), ENGINE_RES_MEDIUM_X - 16.0, ENGINE_RES_MEDIUM_Y - 16.0, INVERTED);
			break;
		case ENGINE_RES_LARGE:
			display = al_create_display(ENGINE_RES_LARGE_X, ENGINE_RES_LARGE_Y);
			Logger::getLogger().logNormal("Created " + std::to_string(ENGINE_RES_LARGE_X) + "x" + std::to_string(ENGINE_RES_LARGE_Y) + " display");
			bbox = new BoundingBox(new Point(ENGINE_RES_LARGE_X / 2.0, ENGINE_RES_LARGE_Y / 2.0), ENGINE_RES_LARGE_X - 16.0, ENGINE_RES_LARGE_Y - 16.0, INVERTED);
			break;
		default:
			Logger::getLogger().logError("Unresolved display resolution");
			showError("Unresolved display resolution");
			return EXIT_FAILURE;
	}

	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	al_hide_mouse_cursor(display);

	Logger::getLogger().logSuccess("Display created properly");


	return EXIT_SUCCESS;
}

void Engine::showError(std::string msg) {
	al_show_native_message_box(display, "Engine error", "Error", msg.c_str(), NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void Engine::prepareLoop() {
	al_start_timer(timer);
	
	Logger::getLogger().logSuccess("Main loop started");
}

bool Engine::updateFrame(Player *player) {
	ALLEGRO_EVENT event;
	al_wait_for_event(eventQueue, &event);

	if (event.type == ALLEGRO_EVENT_TIMER) {
		redrawFrame = true;
	} else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || getKeys()[KEY_ESC] == true) {
		return false;
	} else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_W:
				key[KEY_W] = true;
				break;
			case ALLEGRO_KEY_S:
				key[KEY_S] = true;
				break;
			case ALLEGRO_KEY_D:
				key[KEY_D] = true;
				break;
			case ALLEGRO_KEY_A:
				key[KEY_A] = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				key[KEY_ESC] = true;
				break;
		}
	} else if (event.type == ALLEGRO_EVENT_KEY_UP) {
		switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_W:
				key[KEY_W] = false;
				break;
			case ALLEGRO_KEY_S:
				key[KEY_S] = false;
				break;
			case ALLEGRO_KEY_D:
				key[KEY_D] = false;
				break;
			case ALLEGRO_KEY_A:
				key[KEY_A] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				key[KEY_ESC] = false;
				break;
		}
	}

	if (event.type == ALLEGRO_EVENT_MOUSE_AXES || event.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
		mouseInfo.x = event.mouse.x;
		mouseInfo.y = event.mouse.y;
	} else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		mouseInfo.isClicked = true;
	} else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		mouseInfo.isClicked = false;
	}

	if (redrawFrame && al_is_event_queue_empty(eventQueue)) {
		drawer->drawBoundingBox(bbox);

		for (auto bullet : Bullet::bullets) {
			Point *previousPosition = new Point(bullet->getPosition()->getX(), bullet->getPosition()->getY());
			bullet->update();

			drawer->drawBoundingBox(bullet->getBoundingBox());
			if (bullet->getBoundingBox()->checkForCollisions()) {
				bullet->getPosition()->change(previousPosition->getX(), previousPosition->getY());
			} else {
				drawer->drawBullet(bullet, new Color(255, 255, 0));
			}
		}		

		player->updatePosition();
	
		redrawFrame = false;
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	return true;
}

bool *Engine::getKeys() {
	return key;
}

MouseInfo Engine::getMouse() {
	return mouseInfo;
}

Drawer *Engine::getDrawerInstance() {
	return drawer;
}
