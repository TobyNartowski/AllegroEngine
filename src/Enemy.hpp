#pragma once

#include "Point.hpp"
#include "BoundingBox.hpp"
#include "Player.hpp"
#include "Color.hpp"

#define TEXTURE_PATH "resources/ghost.png"

class Enemy {
	Point *position;
	ALLEGRO_BITMAP *texture;

	int hp;
	int size;
	float speed;
	float ang;

	BoundingBox *bbox;
public:
	static std::vector<Enemy*> enemies;
	Enemy(Point *position, int size = 16, float speed = 3.0, int hp = 60);

	Point *getPosition();
	int getSize();
	BoundingBox *getBoundingBox();
	ALLEGRO_BITMAP *getBitmap();

	bool bulletCheck();
	void updatePosition(Player *player);
};
