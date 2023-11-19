#include "Rectangle.h"
#include <iostream>
#include <sstream>
#include "Figure.h"
#include "../doubleEQ.h"

std::unique_ptr<Figure> Rectangle::clone() const {
	return std::make_unique<Rectangle>(Rectangle(*this));
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

bool Rectangle::equals(Figure* other) const {
	Rectangle* rec = dynamic_cast<Rectangle*>(other);

	if (!rec) {
		return false;
	}

	return *this == *rec;
}