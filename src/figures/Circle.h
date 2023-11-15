#pragma once
#include <string>
#include "Figure.h"
#include <memory>

class Circle : public Figure {
	double r = 1;

public:
	Circle() = default;
	Circle(double r);

	std::unique_ptr<Figure> clone() const override;

	double perimeter() const override;

	std::string ToString() const override;

	bool operator==(Figure* other) const override;

	bool operator==(const Circle& other) const;
};