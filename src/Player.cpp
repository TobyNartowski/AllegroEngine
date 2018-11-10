#include "Player.hpp"

#include "Engine.hpp"

Player::Player(Point *position, int size, float speed) {
	this->position = position;
	this->size = size;
	this->speed = speed;
	crosshairPosition = new Point(0, 0);
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

void Player::updateCrosshair() {
	MouseInfo mouse = Engine::getEngine().getMouse();

	crosshairPosition->change(mouse.x, mouse.y);
}

void Player::updatePosition() {
	bool *key = Engine::getEngine().getKeys();

	if (key[KEY_W] == true) {
		position->move(0, -speed);
	}
	if (key[KEY_S] == true) {
		position->move(0, speed);
	}
	if (key[KEY_A] == true) {
		position->move(-speed, 0);
	}
	if (key[KEY_D] == true) {
		position->move(speed, 0);
	}

	updateCrosshair();
}

