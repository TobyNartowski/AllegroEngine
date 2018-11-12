#pragma once

#include "Point.hpp"
#include "Color.hpp"
#include "LineSegment.hpp"
#include "Viewport.hpp"
#include "Circle.hpp"
#include "Player.hpp"
#include "BoundingBox.hpp"
#include "Bullet.hpp"
#include "Rectangle.hpp"
#include "Enemy.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>
#include <vector>

#define BACKGROUND_PATH "resources/bg.jpg"
#define FONT_PATH "resources/font.ttf"

class Drawer {
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *background;
	ALLEGRO_FONT *font;
	int width, height;

	void helpDrawLine(int x, int x2, int x3, int xi, int y, int y3, int yi, int flag, Color *color);
public:
	Drawer(ALLEGRO_DISPLAY *display, int width, int height);

	void fillBackground(Color *color);
	void drawBackground();

	void drawPoint(Point *point, Color *color);
	void drawPoints(std::vector<Point*> points, Color *color);

	void drawRectangle(Point *upperLeftPoint, Point *lowerRightPoint, Color *color, float thickness);
	void drawTriangle(Point *upperPoint, Point *leftPoint, Point *rightPoint, Color *color, float thickness);
	void drawEllipse(Point *center, int radiusX, int radiusY, Color *color, float thickness);
	void drawCircle(Circle *circle, Color *color, float thickness);

	void drawLine(LineSegment *line, Color *color);
	void drawMultipleLines(std::vector<LineSegment*> lines, Color *color);

	void drawViewport(Viewport *viewport, Color *color);

	void drawPlayer(Player *player);
	void drawEnemy(Enemy *Enemy);
	void drawCrosshair(Player *player);

	void drawBoundingBox(BoundingBox *boundingBox);
	void drawBullet(Bullet *bullet, Color *color);

	void drawRectangle(Rectangle *rectangle);
	void drawRectangle(std::vector<Rectangle*> rectangles);

	void drawScore(int score);
	void drawHp(int hp, int fullHp);
	void drawGameOver(int score);
};
