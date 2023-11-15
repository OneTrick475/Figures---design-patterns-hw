#include "FigureFactoryFactory.h"
#include <fstream>
#include "RandomFigureFactory.h"
#include "StreamFigureFactory.h"
#include <iostream>

std::unique_ptr<FigureFactory> FigureFactoryFactory::create(const std::string type, std::istream& is) {
	if(type == "random") {
		return std::make_unique<RandomFigureFactory>(RandomFigureFactory());
	}
	if(type == "cin") {
		return std::make_unique<StreamFigureFactory>(StreamFigureFactory(std::cin));
	}
	if (type == "file") {
		std::string fileName;
		std::getline(is, fileName);
		std::ifstream file(fileName);

		if (!file.is_open()) {
			throw std::runtime_error("couldnt open file");
		}


		return std::unique_ptr<StreamFigureFactory>(new StreamFigureFactory(std::move(file)));
	}
	throw std::invalid_argument("invalid factory type");
}
