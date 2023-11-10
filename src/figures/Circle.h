#pragma once
#include <string>
#include "Figure.h"

class Circle : public Figure {
	double r = 1;

public:
	Circle() = default;
	Circle(double r);

	Figure* clone() const override;

	double perimeter() const override;

	std::string ToString() const override;

	bool operator==(const Circle& other) const;
};