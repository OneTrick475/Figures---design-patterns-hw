#pragma once
#include "Figure.h"

class Triangle : public Figure {
	double a = 1;
	double b = 1;
	double c = 1;

public:
	Triangle() = default;
	Triangle(double a, double b, double c);

	Figure* clone() const override;

	double perimeter() const override;

	bool operator==(const Triangle& other) const;
};