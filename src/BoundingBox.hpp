#pragma once

#include "Point.hpp"
#include "Color.hpp"

#include <iostream>
#include <vector>

class BoundingBox {
private:
	Point *center;
	float width, height;
	Color *color;
	bool inverted;
public:
	static std::vector<BoundingBox*> objects;

	BoundingBox(Point *center, float width, float height, bool inverted = false);

	Point *getCenterPoint();
	float getWidth();
	float getHeight();
	Color *getColor();
	bool isInverted();

	void move(float dx, float dy);
	void change(Point *center);

	bool checkForCollisions();
};
