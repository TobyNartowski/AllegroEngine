#include "Color.hpp"

Color::Color(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

int Color::getR() {
	return r;
}

int Color::getG() {
	return g;
}

int Color::getB() {
	return b;
}

void Color::change(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

ALLEGRO_COLOR Color::getAllegroColor() {
	return al_map_rgb(r, g, b);
}
