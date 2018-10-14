#include "Engine.hpp"

#include <iostream>

Engine::Engine() {}

Engine &Engine::getEngine() {
	static Engine instance;
	return instance;
}

int Engine::initAllegro() {
	std::cout << "Init allegro here" << std::endl;
	return 0;
}
