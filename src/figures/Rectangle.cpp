#include "Rectangle.h"
#include <iostream>
#include <sstream>
#include "Figure.h"
#include "../doubleEQ.h"

Figure* Rectangle::clone() const {
	return new Rectangle(*this);
}

Rectangle::Rectangle(double a, double b) {
	if (a <= 0 || b <= 0) {
		throw std::invalid_argument("negative or 0 side");
	}
	this->a = std::min(a, b);
	this->b = std::max(a, b);
}

double Rectangle::perimeter() const {
	return a + b;
}

std::string Rectangle::ToString() const {
	std::ostringstream ss;
	ss << a << ' ' << b;
	return "rectangle " + ss.str();
}

bool Rectangle::operator==(const Rectangle& other) const {
	return doublesEQ(a, other.a) && doublesEQ(b, other.b);
}