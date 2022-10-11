#pragma once

#include "ofImage.h"
#include "point.h"

// Refactored from struct (public members)
// to a class with private members.
class Ship {
private:
	Point coordinate;
	Point speed;
	ofImage avatar;

	enum class State { moving, hovered, paused };
	State state { State::moving };
public:

	Ship(const std::string& avatarFilename, const Point& coordinate, const Point& speed);
	Ship(const std::string& avatarFilename, double x, double y, double xSpeed, double ySpeed);
	Ship(const ofImage& avatar, const Point& coordinate, const Point& speed);

	void move();
	void draw() const;
	
	void processMouse(int mouseX, int mouseY, bool isMousePressed);

	friend std::ostream& operator<<(std::ostream& out, const Ship& ship);
	
private:
	void bounceOnEdge();
	bool isShipHovered (int mouseX, int mouseY) const;
};