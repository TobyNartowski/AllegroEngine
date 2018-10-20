#include "Drawer.hpp"

#include <allegro5/allegro_primitives.h>
#include <cmath>

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

void Drawer::drawLineIncrementalAlgorithm(LineSegment *line, Color *color) {
	//TODO: Chujowo dziala, do poprawy
	Point *first = line->getFirstPoint();
	Point *second = line->getSecondPoint();

	float dx = second->getX() - first->getX();
	float dy = second->getY() - first->getY();
	float m = dy / dx;


	if (std::abs(m) <= 1) {
		float y = first->getY();
		for (int x = first->getX(); x <= second->getX(); x++) {
			al_draw_pixel(x, (int) (0.5 + y), color->getAllegroColor());
			y += m;
		}
	} else {
		float x = first->getX();
		m = dx / dy;
		for (int y = second->getY(); y <= first->getY(); y++) {
			al_draw_pixel((int) (x + 0.5), y, color->getAllegroColor());
			x += m;
		}
	}
}

void Drawer::drawMultipleLines(std::vector<LineSegment*> lines, Color *color) {
	for (auto line : lines) {
		drawLineIncrementalAlgorithm(line, color);
	}
}
