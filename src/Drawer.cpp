#include "Drawer.hpp"

Drawer::Drawer(ALLEGRO_DISPLAY *display)
{
	this->display = display;
}

void Drawer::fillBackground(Color *color) {
	al_clear_to_color(al_map_rgb(color->getR(), color->getG(), color->getB()));
}

void Drawer::drawPoint(Point *point, Color *color) {
	al_draw_pixel(point->getX(), point->getY(), al_map_rgb(color->getR(), color->getG(), color->getB()));
}

void Drawer::drawPoints(std::vector<Point*> points, Color *color) {
	for (auto point : points) {
		al_draw_pixel(point->getX(), point->getY(), al_map_rgb(color->getR(), color->getG(), color->getB()));
	}
}
