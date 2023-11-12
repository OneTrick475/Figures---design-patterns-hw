#include <iostream>
#include <filesystem>
#include <thread>

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
	RandomFigureFactory* fac = new RandomFigureFactory();

	int i = 0;
	while (i++ < 100) {
		auto fig = fac->createFigure();

		std::cout << fig.get()->ToString() << '\n';
	}
}