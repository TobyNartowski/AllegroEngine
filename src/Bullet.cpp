#include "Bullet.hpp"

#include <cmath>

std::vector<Bullet*> Bullet::bullets;

Bullet::Bullet(Point *start, Point *direction) {
	this->start = start;
	this->direction = direction;
	actual = new Point(start->getX(), start->getY());
	bbox = new BoundingBox(actual, 8, 8, BULLET);

	ang = std::atan2(start->getY() - direction->getY(), start->getX() - direction->getX());

	bullets.push_back(this);
}

float Bullet::getSpeed() {
	return speed;
}

Point *Bullet::getPosition() {
	return actual;
}

BoundingBox *Bullet::getBoundingBox() {
	return bbox;
}

void Bullet::update() {
	actual->move(-std::cos(ang) * speed, -std::sin(ang) * speed);
}
