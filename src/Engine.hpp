#pragma once

class Engine {
private:
	Engine();
public:
	static Engine& getEngine();

	Engine(Engine const&) = delete;
	void operator=(Engine const&) = delete;

	int initAllegro();
};
