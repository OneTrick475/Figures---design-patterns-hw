#pragma once
#include "FigureFactory.h"
#include <memory>

class FigureFactoryFactory {
public:
	static std::unique_ptr<FigureFactory> create(const std::string type);
};