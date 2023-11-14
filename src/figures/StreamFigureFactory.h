#pragma once
#include "FigureFactory.h"
#include <iostream>

class StreamFigureFactory : public FigureFactory {
	std::istream& input = std::cin;

public:
	StreamFigureFactory() = default;
	StreamFigureFactory(std::istream& input);
	StreamFigureFactory(std::istream&& input);

	virtual std::unique_ptr<Figure> createFigure() override;
};