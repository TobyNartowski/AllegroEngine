#pragma once

#include "Point.hpp"
#include "Color.hpp"
#include "BoundingBox.hpp"

class Rectangle {
private:
	Point *center;
	float width, height;
	Color *color;
	BoundingBox *bbox;
public:
	Rectangle(Point *center, float width, float height, Color *color);

	float getWidth();
	float getHeight();
	Color *getColor();
	Point *getCenterPoint();
};
