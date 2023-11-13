#pragma once
#include "FigureFactory.h"
#include "StreamFigureFactory.h"
#include <iostream>
#include <string>

class FileStreamFigureFactory : public StreamFigureFactory {
	std::unique_ptr<std::ifstream> file;

public:
	FileStreamFigureFactory(const std::string& fileName);

	std::unique_ptr<Figure> createFigure() override;
};