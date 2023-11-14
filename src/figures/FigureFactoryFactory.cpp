#include "FigureFactoryFactory.h"
#include <fstream>
#include "RandomFigureFactory.h"
#include "StreamFigureFactory.h"


std::unique_ptr<FigureFactory> FigureFactoryFactory::create(const std::string type) {
	if(type == "random") {
		return std::make_unique<RandomFigureFactory>(RandomFigureFactory());
	}
	if(type == "cin") {
		return std::make_unique<StreamFigureFactory>(StreamFigureFactory(std::cin));
	}
	if (type == "file") {
		std::string fileName;
		std::cin >> fileName;
		std::ifstream file(fileName);

		return std::make_unique<StreamFigureFactory>(StreamFigureFactory(std::move(file)));
	}
	throw std::invalid_argument("invalid factory type");
}
