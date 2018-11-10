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
public:
	static std::vector<BoundingBox*> objects;

	BoundingBox(Point *center, float width, float height);

	Point *getCenterPoint();
	float getWidth();
	float getHeight();
	Color *getColor();

	void move(float dx, float dy);
	void change(Point *center);

	bool checkForCollisions();
};
