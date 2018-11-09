#include "Viewport.hpp"

Viewport::Viewport(Point *upperLeft, Point *lowerRight) {
	this->upperLeft = upperLeft;
	this->lowerRight = lowerRight;
}

Point *Viewport::getUpperLeft() {
	return upperLeft;
}

Point *Viewport::getLowerRight() {
	return lowerRight;
}

void Viewport::changePoints(Point *upperLeft, Point *lowerRight) {
	if (upperLeft != nullptr) {
		this->upperLeft = upperLeft;
	}
	if (lowerRight != nullptr) {
		this->lowerRight = lowerRight;
	}
}

void Viewport::move(float dx, float dy) {
	upperLeft->move(dx, dy);
	lowerRight->move(dx, dy);
}

float Viewport::getLeft() {
	return upperLeft->getX();
}

float Viewport::getRight() {
	return lowerRight->getX();
}

float Viewport::getTop() {
	return upperLeft->getY();
}

float Viewport::getBottom() {
	return lowerRight->getY();
}
unsigned char Viewport::calculateRegionCode(Point *point) {
	unsigned char result = 0;

	if (point->getX() < getLeft())		result |= 0x1;
	if (point->getX() > getRight())		result |= 0x2;
	if (point->getY() > getBottom())	result |= 0x4;
	if (point->getY() < getTop())		result |= 0x8;

	return result;
}

LineSegment *Viewport::clip(LineSegment *lineSegment) {
	unsigned char rcode1, rcode2, rcode;
	float x, y;
	Point *first = new Point(lineSegment->getFirstPoint()->getX(), lineSegment->getFirstPoint()->getY());
	Point *second = new Point(lineSegment->getSecondPoint()->getX(), lineSegment->getSecondPoint()->getY());
	LineSegment *line = new LineSegment(first, second);

	rcode1 = calculateRegionCode(line->getFirstPoint());
	rcode2 = calculateRegionCode(line->getSecondPoint());

	if (rcode1 & rcode2) {
		return new LineSegment(new Point(-1, -1), new Point(-1, -1));
	}

	if ((rcode1 | rcode2) == 0) {
		return line;
	}

	do {
		Point *first = line->getFirstPoint();
		Point *second = line->getSecondPoint();

		if (rcode1 != 0) {
			rcode = rcode1;
		} else {
			rcode = rcode2;
		}

		if (rcode & 0x1) {
			y = first->getY() + (second->getY() - first->getY()) * (getLeft() - first->getX()) / (second->getX() - first->getX());
			x = getLeft();
		} else if (rcode & 0x2) {
			y = first->getY() + (second->getY() - first->getY()) * (getRight() - first->getX()) / (second->getX() - first->getX());
			x = getRight();
		} else if (rcode & 0x4) {
			x = first->getX() + (second->getX() - first->getX()) * (getBottom() - first->getY()) / (second->getY() - first->getY());
			y = getBottom();
		} else if (rcode & 0x8) {
			x = first->getX() + (second->getX() - first->getX()) * (getTop() - first->getY()) / (second->getY() - first->getY());
			y = getTop();
		}

		if (rcode == rcode1) {
			line->getFirstPoint()->change(x, y);
			rcode1 = calculateRegionCode(line->getFirstPoint());
		} else {
			line->getSecondPoint()->change(x, y);
			rcode2 = calculateRegionCode(line->getSecondPoint());
		}
	} while ((rcode1 & rcode2) == 0 && (rcode1 | rcode2) != 0);

	if ((rcode1 | rcode2) == 0) {
		return line;
	} else {
		return new LineSegment(new Point(-1, -1), new Point(-1, -1));
	}
}

std::vector<LineSegment*> Viewport::clip(std::vector <LineSegment*> linesVector) {
	std::vector <LineSegment*> lines;
	for (auto lineSegment : linesVector) {
		unsigned char rcode1, rcode2, rcode;
		float x, y;
		Point *first = new Point(lineSegment->getFirstPoint()->getX(), lineSegment->getFirstPoint()->getY());
		Point *second = new Point(lineSegment->getSecondPoint()->getX(), lineSegment->getSecondPoint()->getY());
		LineSegment *line = new LineSegment(first, second);

		rcode1 = calculateRegionCode(line->getFirstPoint());
		rcode2 = calculateRegionCode(line->getSecondPoint());

		if (rcode1 & rcode2) {
			continue;
		}

		if ((rcode1 | rcode2) == 0) {
			lines.push_back(line);
		}

		do {
			Point *first = line->getFirstPoint();
			Point *second = line->getSecondPoint();

			if (rcode1 != 0) {
				rcode = rcode1;
			} else {
				rcode = rcode2;
			}

			if (rcode & 0x1) {
				y = first->getY() + (second->getY() - first->getY()) * (getLeft() - first->getX()) / (second->getX() - first->getX());
				x = getLeft();
			} else if (rcode & 0x2) {
				y = first->getY() + (second->getY() - first->getY()) * (getRight() - first->getX()) / (second->getX() - first->getX());
				x = getRight();
			} else if (rcode & 0x4) {
				x = first->getX() + (second->getX() - first->getX()) * (getBottom() - first->getY()) / (second->getY() - first->getY());
				y = getBottom();
			} else if (rcode & 0x8) {
				x = first->getX() + (second->getX() - first->getX()) * (getTop() - first->getY()) / (second->getY() - first->getY());
				y = getTop();
			}

			if (rcode == rcode1) {
				line->getFirstPoint()->change(x, y);
				rcode1 = calculateRegionCode(line->getFirstPoint());
			} else {
				line->getSecondPoint()->change(x, y);
				rcode2 = calculateRegionCode(line->getSecondPoint());
			}
		} while ((rcode1 & rcode2) == 0 && (rcode1 | rcode2) != 0);

		if ((rcode1 | rcode2) == 0) {
			lines.push_back(line);
		} else {
			continue;
		}
	}

	return lines;
}
