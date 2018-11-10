#pragma once

#include "Point.hpp"

class Player {
private:
	Point *position;
	Point *crosshairPosition;
	int size;
	float speed;

	void updateCrosshair();
public: 
	Player(Point *position, int size = 16, float speed = 5.0);

	Point *getPosition();
	Point *getCrosshairPosition();
	int getSize();

	void updatePosition();
};
