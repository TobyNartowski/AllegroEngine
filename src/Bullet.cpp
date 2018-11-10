#include "Bullet.hpp"

#include <cmath>

std::vector<Bullet*> Bullet::bullets;

Bullet::Bullet(Point *start, Point *direction) {
	this->start = start;
	this->direction = direction;
	actual = new Point(start->getX(), start->getY());

	ang = std::atan2(start->getY() - direction->getY(), start->getX() - direction->getX());

	bullets.push_back(this);
}

float Bullet::getSpeed() {
	return speed;
}

Point *Bullet::getPosition() {
	return actual;
}

void Bullet::update() {
	actual->move(-std::cos(ang) * speed, -std::sin(ang) * speed);
}
