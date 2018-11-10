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

	void updateCrosshair();
public: 
	Player(Point *position, int size = 16, float speed = 5.0);

	Point *getPosition();
	Point *getCrosshairPosition();
	int getSize();
	BoundingBox *getBoundingBox();

	void updatePosition();
};
