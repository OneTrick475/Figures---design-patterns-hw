#pragma once
#include "Figure.h"

class Rectangle : public Figure {
	double a = 1;
	double b = 1;

public:
	Rectangle() = default;
	Rectangle(double a, double b);

	Figure* clone() const override;

	double perimeter() const override;

	bool operator==(const Rectangle& other) const;
};