#include "Bullet.hpp"

#include <cmath>

std::vector<Bullet*> Bullet::bullets;

Bullet::Bullet(Point *start, Point *direction) {
	this->start = start;
	this->direction = new Point(direction->getX() + rand() % 100 / 3.0, direction->getY() + rand() % 100 / 3.0);
	actual = new Point(start->getX(), start->getY());
	bbox = new BoundingBox(actual, 8, 8, BULLET);

	ang = std::atan2(start->getY() - this->direction->getY(), start->getX() - this->direction->getX());

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
