#pragma once
#include <string>

class Figure {
public:
	virtual std::unique_ptr<Figure> clone() const = 0;

	virtual double perimeter() const = 0;

	virtual std::string ToString() const = 0;

	virtual ~Figure() = default;
};

