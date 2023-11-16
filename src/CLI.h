#pragma once
#include <memory>
#include <iostream>
#include "figures/FigureFactory.h"
#include <vector>

const int MAX_FIGURES = 5000;

class CLI {
	std::unique_ptr<FigureFactory> fac;
	std::vector<std::unique_ptr<Figure>> figures;

	int getOption(int min, int max) const;
	std::unique_ptr<FigureFactory> getFacFromInput() const;

	void getFigures(int num);
	void outputFigures(std::ostream& os) const;
	void removeFigure(int index);
	void duplicateFigure(int index);

public:
	void run();
};