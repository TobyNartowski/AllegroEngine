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
	if (thickness != 0.0) {
		al_draw_rectangle(upperLeftPoint->getX(), upperLeftPoint->getY(), lowerRightPoint->getX(),
				lowerRightPoint->getY(), color->getAllegroColor(), thickness);
	} else {
		al_draw_filled_rectangle(upperLeftPoint->getX(), upperLeftPoint->getY(), lowerRightPoint->getX(),
				lowerRightPoint->getY(), color->getAllegroColor());

	}
}

void Drawer::drawTriangle(Point *upperPoint, Point *leftPoint, Point *rightPoint, Color *color, float thickness) {
	if (thickness != 0.0) {
		al_draw_triangle(upperPoint->getX(), upperPoint->getY(), leftPoint->getX(), leftPoint->getY(),
				rightPoint->getX(), rightPoint->getY(), color->getAllegroColor(), thickness);
	} else {
		al_draw_filled_triangle(upperPoint->getX(), upperPoint->getY(), leftPoint->getX(), leftPoint->getY(),
				rightPoint->getX(), rightPoint->getY(), color->getAllegroColor());
	}
}

void Drawer::drawEllipse(Point *center, int radiusX, int radiusY, Color *color, float thickness) {
	if (thickness != 0.0) {
		al_draw_ellipse(center->getX(), center->getY(), radiusX, radiusY, color->getAllegroColor(), thickness);
	} else {
		al_draw_filled_ellipse(center->getX(), center->getY(), radiusX, radiusY, color->getAllegroColor());
	}
}

void Drawer::drawCircle(Circle *circle, Color *color, float thickness) {
	if (thickness != 0.0) {
		al_draw_circle(circle->getX(), circle->getY(), circle->getRadius(), color->getAllegroColor(), thickness);
	} else {
		al_draw_filled_circle(circle->getX(), circle->getY(), circle->getRadius(), color->getAllegroColor());
	}
}

void Drawer::drawMultipleLines(std::vector<LineSegment*> lines, Color *color) {
	for (auto line : lines) {
		drawLine(line, color);
	}
}

void Drawer::helpDrawLine(int x, int x2, int x3, int xi, int y, int y3, int yi, int flag, Color *color) {
	int t1 = (y3 - x3) * 2;
	int t2 = y3 * 2;
	int t3 = t2 - x3;
	while (x != x2) {
		if (t3 >= 0) {
			x += xi;
			y += yi;
			t3 += t1;
		} else {
			t3 += t2;
			x += xi;
		}

		if (flag == 0) {
			al_draw_pixel(x, y, color->getAllegroColor());
		} else {
			al_draw_pixel(y, x, color->getAllegroColor());
		}
	}
}

void Drawer::drawLine(LineSegment *line, Color *color) {
	int x1 = line->getFirstPoint()->getX();
	int y1 = line->getFirstPoint()->getY();
	int x2 = line->getSecondPoint()->getX();
	int y2 = line->getSecondPoint()->getY();	

	int x3, y3, xi, yi;
	int x = x1, y = y1;

	xi = (x1 < x2) ? 1 : -1;
	x3 = (x1 < x2) ? (x2 - x1) : (x1 - x2);
	yi = (y1 < y2) ? 1 : -1;
	y3 = (y1 < y2) ? (y2 - y1) : (y1 - y2);

	al_draw_pixel(x,y, color->getAllegroColor());

	if (x3 > y3) {
		helpDrawLine(x, x2, x3, xi, y, y3, yi, 0, color);
	} else {
		helpDrawLine(y, y2, y3, yi, x, x3, xi, 1, color);
	}
}

void Drawer::drawViewport(Viewport *viewport, Color *color) {
	drawRectangle(viewport->getUpperLeft(), viewport->getLowerRight(), color, 1.0);
}

void Drawer::drawPlayer(Player *player) {
	int x = player->getPosition()->getX();
	int y = player->getPosition()->getY();
	int r = player->getSize() / 2;

	al_draw_filled_circle(x, y, r, al_map_rgb(255, 255, 255));
}

void Drawer::drawCrosshair(Player *player) {
	al_draw_circle(player->getCrosshairPosition()->getX(), player->getCrosshairPosition()->getY(), 3, al_map_rgb(255, 0, 0), 0.7);
}

void Drawer::drawBoundingBox(BoundingBox *boundingBox) {
	Point *center = boundingBox->getCenterPoint();
	float width = boundingBox->getWidth();
	float height = boundingBox->getHeight();
	Point *upperLeft = new Point(center->getX() - (width / 2.0), center->getY() - (height / 2.0));
	Point *lowerRight = new Point(center->getX() + (width / 2.0), center->getY() + (height / 2.0));

	drawRectangle(upperLeft, lowerRight, boundingBox->getColor(), 1.0);
}

void Drawer::drawBullet(Bullet *bullet, Color *color) {
	drawPoint(bullet->getPosition(), color);
}

void Drawer::drawRectangle(Rectangle *rectangle) {
	Point *center = rectangle->getCenterPoint();
	float width = rectangle->getWidth();
	float height = rectangle->getHeight();
	Point *upperLeft = new Point(center->getX() - (width / 2.0), center->getY() - (height / 2.0));
	Point *lowerRight = new Point(center->getX() + (width / 2.0), center->getY() + (height / 2.0));

	drawRectangle(upperLeft, lowerRight, rectangle->getColor(), 0.0);

}

void Drawer::drawRectangle(std::vector<Rectangle*> rectangles) {
	for (auto rect : rectangles) {
		drawRectangle(rect);
	}
}
