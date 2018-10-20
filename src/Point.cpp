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
