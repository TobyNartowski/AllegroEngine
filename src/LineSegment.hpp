#pragma once

#include "Point.hpp"

class LineSegment {
private:
	Point *first;
	Point *second;
public:
	LineSegment(Point *first, Point *second);

	void logLineSegment();
	void changePoints(Point *first, Point *second);

	Point *getFirstPoint();
	Point *getSecondPoint();
};
