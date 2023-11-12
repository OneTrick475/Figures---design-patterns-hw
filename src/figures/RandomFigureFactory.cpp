#include "RandomFigureFactory.h"
#include <sstream>

std::unique_ptr<Figure> RandomFigureFactory::createFigure() {
	int figureType = rand() % 3;

	if(figureType == 0) {
		std::string figure("triangle");

		figure += ' ';

		figure += std::to_string(rand());
		figure += ' ';

		figure += std::to_string(rand());
		figure += ' ';

		figure += std::to_string(rand());

		return createFigureFromStr(figure);
	}
	if (figureType == 1) {
		std::string figure("rectangle");

		figure += ' ';

		figure += std::to_string(rand());
		figure += ' ';

		figure += std::to_string(rand());

		return createFigureFromStr(figure);
	}
	if (figureType == 2) {
		std::string figure("circle");

		figure += ' ';

		figure += std::to_string(rand());

		return createFigureFromStr(figure);
	}
}
