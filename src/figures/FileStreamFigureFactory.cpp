#include "FileStreamFigureFactory.h"
#include <fstream>
#include <iostream>

FileStreamFigureFactory::FileStreamFigureFactory(const std::string& fileName) {
	std::ifstream file(fileName);
	std::string str;
	file >> str;
	file >> str;
	std::cout << str;
}

std::unique_ptr<Figure> FileStreamFigureFactory::createFigure() {
	std::string line;
	std::getline(*file, line);

	return FigureFactory::createFigureFromStr(line);
}
