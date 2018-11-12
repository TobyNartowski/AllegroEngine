#pragma once

#include "Point.hpp"
#include "BoundingBox.hpp"

class Player {
private:
	Point *position;
	Point *previousPosition;
	Point *crosshairPosition;
	int size;
	float speed;
	BoundingBox *bbox;
	int hp, fullHp;

	void updateCrosshair();
public: 
	Player(Point *position, int size = 16, float speed = 5.0, int hp = 100);

	Point *getPosition();
	Point *getCrosshairPosition();

	int getSize();
	BoundingBox *getBoundingBox();
	int getHp();
	int getFullHp();
	int subtractHp(int value);

	void updatePosition();
};
