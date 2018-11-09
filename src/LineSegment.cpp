#include "LineSegment.hpp"
#include "Logger.hpp"

#include <iostream>

LineSegment::LineSegment(Point *first, Point *second) {
	this->first = first;
	this->second = second;
}

void LineSegment::logLineSegment() {
	Logger::getLogger().logNormal("LineSegment: [ P1(" + std::to_string(first->getX()) + ", " + std::to_string(first->getY()) +
					"), P2(" + std::to_string(second->getX()) + ", " + std::to_string(second->getY()) + ") ]");
}

void LineSegment::changePoints(Point *first, Point *second) {
	if (first != nullptr) {
		this->first = first;
	}

	if (second != nullptr) {
		this->second = second;
	}
}

Point *LineSegment::getFirstPoint() {
	return first;
}

Point *LineSegment::getSecondPoint() {
	return second;
}
