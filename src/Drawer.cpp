#include "Drawer.hpp"

#include <allegro5/allegro_primitives.h>

Drawer::Drawer(ALLEGRO_DISPLAY *display)
{
	this->display = display;
}

void Drawer::fillBackground(Color *color) {
	al_clear_to_color(color->getAllegroColor());
}

void Drawer::drawPoint(Point *point, Color *color) {
	al_draw_pixel(point->getX(), point->getY(), color->getAllegroColor());
}

void Drawer::drawPoints(std::vector<Point*> points, Color *color) {
	for (auto point : points) {
		al_draw_pixel(point->getX(), point->getY(), color->getAllegroColor());
	}
}

void Drawer::drawRectangle(Point *upperLeftPoint, Point *lowerRightPoint, Color *color, float thickness) {
	al_draw_rectangle(upperLeftPoint->getX(), upperLeftPoint->getY(), lowerRightPoint->getX(),
			 lowerRightPoint->getY(), color->getAllegroColor(), thickness);
}

void Drawer::drawTriangle(Point *upperPoint, Point *leftPoint, Point *rightPoint, Color *color, float thickness) {
	al_draw_triangle(upperPoint->getX(), upperPoint->getY(), leftPoint->getX(), leftPoint->getY(),
			 rightPoint->getX(), rightPoint->getY(), color->getAllegroColor(), thickness);
}

void Drawer::drawEllipse(Point *center, int radiusX, int radiusY, Color *color, float thickness) {
	al_draw_ellipse(center->getX(), center->getY(), radiusX, radiusY, color->getAllegroColor(), thickness);
}
