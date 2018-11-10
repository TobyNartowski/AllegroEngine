#include "BoundingBox.hpp"

#include <cmath>

std::vector<BoundingBox*> BoundingBox::objects;

BoundingBox::BoundingBox(Point *center, float width, float height) {
	this->center = center;
	this->width = width;
	this->height = height;
	color = new Color(0, 255, 0);

	objects.push_back(this);
}

Point *BoundingBox::getCenterPoint() {
	return center;
}

float BoundingBox::getWidth() {
	return width;
}

float BoundingBox::getHeight() {
	return height;
}

Color *BoundingBox::getColor() {
	return color;
}

void BoundingBox::move(float dx, float dy) {
	center->move(dx, dy);
}

void BoundingBox::change(Point *center) {
	this->center = center;
}

bool BoundingBox::checkForCollisions() {
	Point *a = new Point(center->getX(), center->getY());
	for (auto boundingBox : objects) {
		if (boundingBox != this) {
			Point *b = new Point(boundingBox->getCenterPoint()->getX(), boundingBox->getCenterPoint()->getY());

		 	if ((std::abs(a->getX() - b->getX()) * 2.0 <= (width + boundingBox->getWidth())) &&
		         	(std::abs(a->getY() - b->getY()) * 2.0 <= (height + boundingBox->getHeight()))) {
				color->change(255, 0, 0);;
				boundingBox->getColor()->change(255, 0, 0);
				return true;
			} else {
				boundingBox->getColor()->change(0, 255, 0);
			}
		}
	}

	color->change(0, 255, 0);
	return false;
}
