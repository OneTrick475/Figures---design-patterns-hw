#include <iostream>
#include <filesystem>
#include <thread>
#include <fstream>
#include <sstream>

#include "figures/FigureFactoryFactory.h"
#include "figures/RandomFigureFactory.h"
#include <figures/StreamFigureFactory.h>

#include "CLI.h"

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
	CLI cli;
	cli.run();

}