#include <iostream>
#include <filesystem>
#include <thread>
#include <fstream>
#include "figures/FigureFactoryFactory.h"
#include "figures/RandomFigureFactory.h"
#include <figures/StreamFigureFactory.h>

namespace fs = std::filesystem;

void displayUsage(const char* executablePath)
{
	try {
		fs::path ep(executablePath);
		
		std::cout
			<< "Usage:\n\t"
			<< ep.filename()
			<< " <integer>\n";
	}
	catch (...) {
		std::cout << "Cannot parse path from argv[0]";
	}
}

int main()
{
	std::unique_ptr<FigureFactory> fac = std::make_unique<StreamFigureFactory>(
		"C:\\Users\\Ivan Bukev\\Source\\Repos\\Figures---design-patterns-hw3\\src\\figures.txt") ;

	std::cout << fac.get()->createFigure()->ToString();
}