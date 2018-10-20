#pragma once

#include <allegro5/allegro.h>

class Color {
private:
	int r;
	int g;
	int b;
public:
	Color(int r, int g, int b);

	int getR();
	int getG();
	int getB();

	ALLEGRO_COLOR getAllegroColor();
};
