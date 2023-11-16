#include "RandomFigureFactory.h"
#include <sstream>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

RandomFigureFactory::RandomFigureFactory() : generator(0, 2){}

RandomFigureFactory::RandomFigureFactory(int low, int high) : generator(low, high) {}

std::unique_ptr<Figure> RandomFigureFactory::createFigure() {
	const int MAX_SIDE = 1000;

	int figureType = generator.getInRange();

	if(figureType == 0) {
		int a = generator.getInRange(1, MAX_SIDE);

		int b = generator.getInRange(1, MAX_SIDE);

		int max = std::max(a, b);
		int min = std::min(a, b);

		int c = generator.getInRange(max - min + 1, max + min - 1);

		return std::make_unique<Triangle>(a, b, c);
	}
	if (figureType == 1) {
		int a = generator.getInRange(1, MAX_SIDE);

		int b = generator.getInRange(1, MAX_SIDE);

		return std::make_unique<Rectangle>(a, b);
	}
	if (figureType == 2) {
		int r = generator.getInRange(1, MAX_SIDE);

		return std::make_unique<Circle>(r);
	}
}
