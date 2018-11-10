#include "Circle.hpp"

Circle::Circle(Point *center, float radius) {
	this->center = center;
	this->radius = radius;
}

float Circle::getX() {
	return center->getX();
}

float Circle::getY() {
	return center->getY();
}

float Circle::getRadius() {
	return radius;
}
