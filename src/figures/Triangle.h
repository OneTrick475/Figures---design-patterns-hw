#pragma once
#include <string>
#include "Figure.h"
#include <memory>

class Triangle : public Figure {
	double a = 1;
	double b = 1;
	double c = 1;

public:
	Triangle() = default;
	Triangle(double a, double b, double c);

	std::unique_ptr<Figure> clone() const override;

	double perimeter() const override;

	std::string ToString() const override;

	bool operator==(const Triangle& other) const;
};