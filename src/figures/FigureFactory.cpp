#include "FigureFactory.h"
#include <sstream>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

std::unique_ptr<Figure> FigureFactory::createFigureFromStr(const std::string& str) {
	std::stringstream ss(str);

	std::string figure;

	ss >> figure;

	if(figure == "triangle") {
		double a, b, c;
		ss >> a >> b >> c;

		return std::make_unique<Triangle>(Triangle(a, b, c));
	}
	if (figure == "rectangle") {
		double a, b;
		ss >> a >> b;

		return std::make_unique<Rectangle>(Rectangle(a, b));
	}
	if (figure == "circle") {
		double a;
		ss >> a;

		return std::make_unique<Circle>(Circle(a));
	}
}
