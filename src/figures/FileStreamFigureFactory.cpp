#include "FileStreamFigureFactory.h"
#include <fstream>
#include <iostream>

FileStreamFigureFactory::FileStreamFigureFactory(const std::string& fileName) {
	file = std::ifstream(fileName);
}

std::unique_ptr<Figure> FileStreamFigureFactory::createFigure() {
	std::string line;
	std::getline(file, line);

	return FigureFactory::createFigureFromStr(line);
}
