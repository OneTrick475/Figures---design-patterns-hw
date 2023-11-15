#pragma once
#include "FigureFactory.h"
#include <iostream>
#include <fstream>

class StreamFigureFactory : public FigureFactory {
	std::ifstream file;
	std::istream& input;
	
public:
	StreamFigureFactory(std::istream& input);
	StreamFigureFactory(std::ifstream&& fileRef);

	virtual std::unique_ptr<Figure> createFigure() override;
};