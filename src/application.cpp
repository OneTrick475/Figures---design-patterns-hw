#include <iostream>
#include <filesystem>
#include <thread>

#include "figures/FigureFactoryFactory.h"
#include "figures/RandomFigureFactory.h"

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
	std::unique_ptr<FigureFactory> fac = FigureFactoryFactory::create("file");

	std::cout << fac.get()->createFigure()->ToString();
}