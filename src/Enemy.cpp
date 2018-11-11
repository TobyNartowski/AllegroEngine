#include "Enemy.hpp"

#include <cmath>

std::vector<Enemy*> Enemy::enemies;

Enemy::Enemy(Point *position, int size, float speed, int hp) {
	this->position = position;
	this->size = size;
	this->speed = speed;
	this->hp = hp;
	bbox = new BoundingBox(position, size, size, ENEMY);

	enemies.push_back(this);
	color = new Color(255, 0, 0);
}

Point *Enemy::getPosition() {
	return position;
}

int Enemy::getSize() {
	return size;
}

BoundingBox *Enemy::getBoundingBox() {
	return bbox;
}

Color *Enemy::getColor() {
	return new Color(255, hp * 3, 0);
}

bool Enemy::bulletCheck() {
	if (bbox->checkForCollisions()) {
		hp -= 5;
		if (hp <= 0) {
			return false;
		}
	}
	return true;
}

void Enemy::updatePosition(Player *player) {
	Point *playerPosition = player->getPosition();

	ang = std::atan2(position->getY() - playerPosition->getY(), position->getX() - playerPosition->getX());
	position->move(-std::cos(ang) * speed, -std::sin(ang) * speed);
}
