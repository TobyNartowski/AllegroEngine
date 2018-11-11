#pragma once

#include "Point.hpp"
#include "BoundingBox.hpp"
#include "Player.hpp"
#include "Color.hpp"

class Enemy {
	Point *position;

	int hp;
	int size;
	float speed;
	float ang;

	BoundingBox *bbox;
	Color *color;
public:
	static std::vector<Enemy*> enemies;
	Enemy(Point *position, int size = 16, float speed = 3.0, int hp = 255);

	Point *getPosition();
	int getSize();
	BoundingBox *getBoundingBox();
	Color *getColor();

	bool bulletCheck();
	void updatePosition(Player *player);
};
