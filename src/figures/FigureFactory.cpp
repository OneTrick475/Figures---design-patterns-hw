#include "FigureFactory.h"
#include <sstream>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

std::unique_ptr<Figure> FigureFactory::createFigureFromStr(const std::string& str) {
	std::stringstream ss(str);

	std::string figure;

	ss >> figure;

	if(figure == "triangle") {
		double a, b, c;

		ss >> a;

		if (ss.fail())
			throw std::invalid_argument("not enough sides");

		ss >> b;

		if (ss.fail())
			throw std::invalid_argument("not enough sides");

		ss >> c;

		if (ss.fail())
			throw std::invalid_argument("not enough sides");

		return std::make_unique<Triangle>(Triangle(a, b, c));
	}
	if (figure == "rectangle") {
		double a, b;

		ss >> a;

		if (ss.fail())
			throw std::invalid_argument("not enough sides");

		ss >> b;

		if (ss.fail())
			throw std::invalid_argument("not enough sides");

		return std::make_unique<Rectangle>(Rectangle(a, b));
	}
	if (figure == "circle") {
		double a;

		ss >> a;

		if (ss.fail())
			throw std::invalid_argument("not radius");

		return std::make_unique<Circle>(Circle(a));
	}

	throw std::invalid_argument("invalid figure");
}
