#include "Point.hpp"

Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}

float Point::getX() {
	return x;
}

float Point::getY() {
	return y;
}

void Point::move(float dx, float dy) {
	x += dx;
	y += dy;
}

void Point::changePoint(float x, float y)
{
	if (x != -1) {
		this->x = x;
	}

	if (y != -1) {
		this->y = y;
	}
}
