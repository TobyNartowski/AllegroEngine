#pragma once

#include "Point.hpp"
#include "BoundingBox.hpp"

#include <iostream>
#include <vector>

class Bullet {
private:
	Point *start;
	Point *direction;
	Point *actual;
	float ang;
	BoundingBox *bbox;

	float speed = 10.0;
public:
	static std::vector<Bullet*> bullets;

	Bullet(Point *start, Point *direction);
	float getSpeed();
	Point *getPosition();
	BoundingBox *getBoundingBox();

	void update();
};
