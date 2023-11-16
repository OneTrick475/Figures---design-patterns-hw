#include "CLI.h"
#include <cctype>
#include <string>
#include <algorithm>
#include "figures/FigureFactoryFactory.h"
#include "fstream"

int CLI::getOption(int min, int max) const {
	int option;

	std::cin >> option;
	while (std::cin.fail() || option < min || option > max) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		printf("Invalid. Enter a number between %d and %d\n", min, max);
		std::cin >> option;
	}
	return option;
}

void CLI::removeFigure(int index) {
	figures.erase(figures.begin() + index);
}

void CLI::duplicateFigure(int index) {
	figures.insert(figures.begin() + index, figures[index]->clone());
}


void CLI::outputFigures(std::ostream& os) const {
	for(const std::unique_ptr<Figure>& fig : figures) {
		os << fig->ToString() << '\n';
	}
}


void CLI::getFigures(int num) {
	for(int i = 0; i < num; ++i) {
		try {
			std::unique_ptr<Figure> fig = fac->createFigure();
			figures.push_back(std::move(fig));
		}
		catch(const std::invalid_argument& ex) {
			std::cout << ex.what();
			std::exit(1);
		}
	}
}

std::unique_ptr<FigureFactory> CLI::getFacFromInput() const {
	std::cout << "choose how you want to enter figures\n1. random\n2. cin\n3. file\n";

	std::string type;

	std::getline(std::cin, type);

	std::transform(type.begin(), type.end(), type.begin(),
	               [](unsigned char c) { return std::tolower(c); });

	try {
		return FigureFactoryFactory::create(type);
	}
	catch (const std::invalid_argument& ex) {
		std::cout << ex.what();
		std::exit(1);
	}
	catch (const std::runtime_error& ex) {
		std::cout << ex.what();
		std::exit(1);
	}
    
}

void CLI::run() {
	fac = getFacFromInput();

	std::cout << "what number of figures\n";
	int numFigures = getOption(1, MAX_FIGURES);
	getFigures(numFigures);

	while(true) {
		std::cout << "chose an option 1 - 5\n1. Print figures\n2. Save in file\n3. Remove figure\n4. Duplicate figure\n5. Exit\n";

		int option = getOption(1, 5);

		if(option == 1) {
			outputFigures(std::cout);
		}
		else if(option == 2) {
			std::string fileName;
			std::cin >> fileName;

			std::ofstream file("D:\\" + fileName); //had a problem with saving files, for some reason they were not in the current directory, so now i just save them directly in D:\

			if(!file.is_open()) {
				std::cout << "couldnt open file";
				std::exit(1);
			}
			outputFigures(file);
		}
		else if(option == 3) {
			std::cout << "enter figure index\n";
			int index = getOption(0, figures.size() - 1);

			removeFigure(index);
		}
		else if(option == 4) {
			std::cout << "enter figure index\n";
			int index = getOption(0, figures.size() - 1);

			duplicateFigure(index);
		}
		else if(option == 5) {
			std::exit(0);
		}
	}
}