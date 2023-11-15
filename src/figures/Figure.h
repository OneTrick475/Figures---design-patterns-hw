#pragma once
#include <string>
#include <memory>

class Figure {
public:
	virtual std::unique_ptr<Figure> clone() const = 0;

	virtual double perimeter() const = 0;

	virtual std::string ToString() const = 0;

	virtual bool operator==(Figure* other) const = 0;

	virtual ~Figure() = default;
};

