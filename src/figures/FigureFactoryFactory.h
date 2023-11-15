#pragma once
#include "FigureFactory.h"
#include <memory>
#include <iostream>

class FigureFactoryFactory {
public:
	static std::unique_ptr<FigureFactory> create(const std::string type, std::istream& is = std::cin);
};