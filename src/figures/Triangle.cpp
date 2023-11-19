#include "Triangle.h"
#include <iostream>
#include <sstream>
#include "Figure.h"
#include "../doubleEQ.h"\


std::unique_ptr<Figure> Triangle::clone() const {
	return std::make_unique<Triangle>(Triangle(*this));
}

Triangle::Triangle(double a, double b, double c) {
	if(a <= 0 || b <= 0 || c <= 0) {
		throw std::invalid_argument("negative or 0 side");
	}
	this->c = std::max(a, std::max(b, c));
	this->a = std::min(a, std::min(b, c));
	this->b = a + b + c - this->a - this->c;

	if(this->a + this->b <= this->c) {
		throw std::invalid_argument("inequality of the triangle is broken");
	}
}

double Triangle::perimeter() const {
	return a + b + c;
}

bool Triangle::operator==(const Triangle& other) const {
	return doublesEQ(a, other.a) && doublesEQ(b, other.b) && doublesEQ(c, other.c);
}

std::string Triangle::ToString() const {
	std::ostringstream ss;
	ss << a << ' ' << b << ' ' << c;
	return "triangle " + ss.str();
}

bool Triangle::equals(Figure* other) const {
	Triangle* tri = dynamic_cast<Triangle*>(other);

	if (!tri) {
		return false;
	}

	return *this == *tri;
}