#pragma once
#include "FigureFactory.h"
#include "StreamFigureFactory.h"
#include <iostream>
#include <fstream>
#include <string>

class FileStreamFigureFactory : public FigureFactory {
	std::ifstream file;

public:
	FileStreamFigureFactory(const std::string& fileName);

	std::unique_ptr<Figure> createFigure() override;
};