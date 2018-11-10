#include "Rectangle.hpp"

Rectangle::Rectangle(Point *center, float width, float height, Color *color) {
	this->center = center;
	this->width = width;
	this->height = height;
	this->color = color;
	bbox = new BoundingBox(center, width, height);
}

float Rectangle::getWidth() {
	return width;
}

float Rectangle::getHeight() {
	return height;
}

Color *Rectangle::getColor() {
	return color;
}

Point *Rectangle::getCenterPoint() {
	return center;
}
