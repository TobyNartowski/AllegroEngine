#pragma once

#include "Point.hpp"
#include "Color.hpp"
#include "LineSegment.hpp"

#include <allegro5/allegro.h>
#include <iostream>
#include <vector>

class Drawer {
private:
	ALLEGRO_DISPLAY *display;

	void helpDrawLine(int x, int x2, int x3, int xi, int y, int y3, int yi, int flag, Color *color);
public:
	Drawer(ALLEGRO_DISPLAY *display);

	void fillBackground(Color *color);

	void drawPoint(Point *point, Color *color);
	void drawPoints(std::vector<Point*> points, Color *color);

	void drawRectangle(Point *upperLeftPoint, Point *lowerRightPoint, Color *color, float thickness);
	void drawTriangle(Point *upperPoint, Point *leftPoint, Point *rightPoint, Color *color, float thickness);
	void drawEllipse(Point *center, int radiusX, int radiusY, Color *color, float thickness);

	void drawLine(LineSegment *line, Color *color);
	void drawMultipleLines(std::vector<LineSegment*> lines, Color *color);
};
