#include "BoundingBox.hpp"

#include <cmath>

std::vector<BoundingBox*> BoundingBox::objects;

BoundingBox::BoundingBox(Point *center, float width, float height, enum Type type) {
	this->center = center;
	this->width = width;
	this->height = height;
	this->type = type;
	color = new Color(0, 255, 255);

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

enum Type BoundingBox::getType() {
	return type;
}

void BoundingBox::move(float dx, float dy) {
	center->move(dx, dy);
}

void BoundingBox::change(Point *center) {
	this->center = center;
}

bool BoundingBox::checkForCollisions() {
	Point *a = new Point(center->getX(), center->getY());
	bool collision;

	for (auto boundingBox : objects) {
		if (boundingBox != this) {
			if ((boundingBox->getType() == BULLET && type == BULLET) || 
				(boundingBox->getType() == BULLET && type == PLAYER) ||
				(boundingBox->getType() == PLAYER && type == BULLET) ||
				(boundingBox->getType() == BULLET && type == INVERTED) ||
				(boundingBox->getType() == INVERTED && type == BULLET) ||
				(boundingBox->getType() == NONE && type == ENEMY) ||
				(boundingBox->getType() == ENEMY && type == NONE) || 
				(boundingBox->getType() == INVERTED && type == ENEMY) ||
				(boundingBox->getType() == ENEMY && type == INVERTED)) {
				continue;
			}

			Point *b = new Point(boundingBox->getCenterPoint()->getX(), boundingBox->getCenterPoint()->getY());
		 	collision = (std::abs(a->getX() - b->getX()) * 2.0 <= (width + boundingBox->getWidth())) &&
		         	(std::abs(a->getY() - b->getY()) * 2.0 <= (height + boundingBox->getHeight()));

			if (boundingBox->getType() == INVERTED) {
				collision = !collision;
			}

			if (collision) {
				color->change(255, 0, 0);
				boundingBox->getColor()->change(255, 0, 0);
				return true;
			} else {
				boundingBox->getColor()->change(0, 255, 255);
			}
		}
	}

	color->change(0, 255, 255);
	return false;
}

