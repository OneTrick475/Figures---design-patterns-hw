#pragma once
#include <memory>
#include "Figure.h"
#include <string>

class FigureFactory {
public:
	static std::unique_ptr<Figure> createFigureFromStr(const std::string& str);

	virtual std::unique_ptr<Figure> createFigure() = 0;

	virtual ~FigureFactory() = default;
};