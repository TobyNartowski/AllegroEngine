#pragma once

class Point {
private:
	float x;
	float y;
public:
	Point(float x, float y);

	float getX();
	float getY();

	void move(float dx, float dy);
	void change(float x, float y);
};
