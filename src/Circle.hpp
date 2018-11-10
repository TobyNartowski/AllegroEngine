#pragma once

#include "Point.hpp"

class Circle {
private:
	Point *center;
	float radius;
public:
	Circle(Point *center, float radius);

	float getX();
	float getY();
	float getRadius();
};
