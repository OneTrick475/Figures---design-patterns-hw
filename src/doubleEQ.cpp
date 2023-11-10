#include <iostream>
#include "doubleEQ.h"

bool doublesEQ(double first, double second) {
	const auto relative_difference_factor = 0.0001;
	const auto greater_magnitude = std::max(std::abs(first), std::abs(second));

	return std::abs(first - second) < relative_difference_factor * greater_magnitude;
}