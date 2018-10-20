#pragma once

#include "Point.hpp"
#include "Color.hpp"

#include <allegro5/allegro.h>
#include <iostream>
#include <vector>

class Drawer {
private:
	ALLEGRO_DISPLAY *display;
public:
	Drawer(ALLEGRO_DISPLAY *display);

	void fillBackground(Color *color);
	void drawPoint(Point *point, Color *color);
	void drawPoints(std::vector<Point*> points, Color *color);
};
