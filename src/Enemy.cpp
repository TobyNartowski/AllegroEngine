#include "Enemy.hpp"
#include "Logger.hpp"

#include <cmath>

static bool messageShown = false;

std::vector<Enemy*> Enemy::enemies;

Enemy::Enemy(Point *position, int size, float speed, int hp) {
	this->position = position;
	this->size = size;
	this->speed = speed;
	this->hp = hp;
	bbox = new BoundingBox(position, size, size, ENEMY);

	enemies.push_back(this);

	texture = al_load_bitmap(TEXTURE_PATH);
	if (!texture && !messageShown) {
		messageShown = true;
		Logger::getLogger().logError("Failed to load ghost texture");
	}
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

ALLEGRO_BITMAP *Enemy::getBitmap() {
	return texture;
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
