#include "Circle.h"
#include <iostream>
#include "Figure.h"
#include "../doubleEQ.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>

std::unique_ptr<Figure> Circle::clone() const {
	return std::make_unique<Circle>(Circle(*this));
}

Circle::Circle(double r) {
	if (r <= 0) {
		throw std::invalid_argument("negative or 0 radius");
	}
	this->r = r;
}

double Circle::perimeter() const {
	return 2 * M_PI * r ;
}

std::string Circle::ToString() const {
	std::ostringstream ss;
	ss << r;
	return "circle " + ss.str();
}

bool Circle::operator==(const Circle& other) const {
	return doublesEQ(r, other.r) ;
}