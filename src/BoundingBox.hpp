#pragma once

#include "Point.hpp"
#include "Color.hpp"

#include <iostream>
#include <vector>

enum Type {
	NONE, INVERTED, BULLET, PLAYER, ENEMY
};


class BoundingBox {
private:
	Point *center;
	float width, height;
	Color *color;
	bool inverted;
	bool bullet;
	bool player;
	enum Type type;
public:
	static std::vector<BoundingBox*> objects;

	BoundingBox(Point *center, float width, float height, enum Type type = NONE);

	Point *getCenterPoint();
	float getWidth();
	float getHeight();
	Color *getColor();
	enum Type getType();

	void move(float dx, float dy);
	void change(Point *center);

	bool checkForCollisions();
	bool checkForDamage();
};
