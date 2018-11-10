#include "Player.hpp"

#include "Engine.hpp"

Player::Player(Point *position, int size, float speed) {
	this->position = position;
	this->size = size;
	this->speed = speed;
	crosshairPosition = new Point(0, 0);
	bbox = new BoundingBox(position, size, size);
	previousPosition = new Point(position->getX(), position->getY());
}

Point *Player::getPosition() {
	return position;
}

Point *Player::getCrosshairPosition() {
	return crosshairPosition;
}

int Player::getSize() {
	return size;
}

BoundingBox *Player::getBoundingBox() {
	return bbox;
}

void Player::updateCrosshair() {
	MouseInfo mouse = Engine::getEngine().getMouse();

	if (mouse.isClicked) {
		new Bullet(position, crosshairPosition);
	}
	crosshairPosition->change(mouse.x, mouse.y);
}

void Player::updatePosition() {
	bool *key = Engine::getEngine().getKeys();

	previousPosition->change(position->getX(), position->getY());

	if (key[KEY_W] == true) {
		position->move(0, -speed);

		if (bbox->checkForCollisions()) {
			position->change(-1.0, previousPosition->getY());
		}
	}
	if (key[KEY_S] == true) {
		position->move(0, speed);
	
		if (bbox->checkForCollisions()) {
			position->change(-1.0, previousPosition->getY());
		}
	}
	if (key[KEY_A] == true) {
		position->move(-speed, 0);

		if (bbox->checkForCollisions()) {
			position->change(previousPosition->getX(), -1.0);
		}
	}
	if (key[KEY_D] == true) {
		position->move(speed, 0);

		if (bbox->checkForCollisions()) {
			position->change(previousPosition->getX(), -1.0);
		}
	}


	updateCrosshair();
}

