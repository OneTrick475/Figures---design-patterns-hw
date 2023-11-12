#pragma once
#include <ctime>

#include "FigureFactory.h"

class RandomFigureFactory : public FigureFactory {
public:
	RandomFigureFactory()  {
		srand(time(0));
	}

	std::unique_ptr<Figure> createFigure() override;
};