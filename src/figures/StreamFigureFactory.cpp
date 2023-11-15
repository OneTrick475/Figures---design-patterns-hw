#include "StreamFigureFactory.h"
#include <fstream>
#include <iostream>

StreamFigureFactory::StreamFigureFactory(std::istream& input) : input(input){}

StreamFigureFactory::StreamFigureFactory(std::ifstream&& fileRef) : file(std::move(fileRef)), input(file) {}

std::unique_ptr<Figure> StreamFigureFactory::createFigure() {
	std::string line;
	std::getline(input, line);

	return FigureFactory::createFigureFromStr(line);
}