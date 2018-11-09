#pragma once

#include "Point.hpp"
#include "LineSegment.hpp"

#include <iostream>
#include <vector>

class Viewport {
private:
	Point *upperLeft, *lowerRight;

	float getLeft();
	float getRight();
	float getTop();
	float getBottom();

	unsigned char calculateRegionCode(Point *point);
public:
	Viewport(Point *upperLeft, Point *lowerRight);

	Point *getUpperLeft();
	Point *getLowerRight();

	void changePoints(Point *upperLeft, Point *lowerRight);
	void move(float dx, float dy);

	LineSegment *clip(LineSegment *lineSegment);
	std::vector<LineSegment*> clip(std::vector <LineSegment*> linesVector);
};
