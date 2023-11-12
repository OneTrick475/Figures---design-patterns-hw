#pragma once
#include "FigureFactory.h"
#include <iostream>

class StreamFigureFactory : public FigureFactory {
	std::istream& input;

public:
	StreamFigureFactory(std::istream& input);

	std::unique_ptr<Figure> createFigure() override;
};