#include "StreamFigureFactory.h"

StreamFigureFactory::StreamFigureFactory(std::istream& input) : input(input){}

std::unique_ptr<Figure> StreamFigureFactory::createFigure() {
	std::string line;
	std::getline(input, line);

	return FigureFactory::createFigureFromStr(line);
}