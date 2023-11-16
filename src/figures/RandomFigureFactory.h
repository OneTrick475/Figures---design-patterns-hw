#pragma once
#include <ctime>
#include <random>
#include "FigureFactory.h"


class RandomGenerator {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution;

public:
	RandomGenerator(int low, int high) : distribution(std::uniform_int_distribution<int>(low, high)), generator(time(0)){}

	int getInRange() {
		return distribution(generator);
	}

	int getInRange(int low, int high) {
		std::uniform_int_distribution<int> distribution(low, high);
		return distribution(generator);
	}
};

class RandomFigureFactory : public FigureFactory {
	RandomGenerator generator;
public:
	RandomFigureFactory();

	RandomFigureFactory(int low, int high);

	std::unique_ptr<Figure> createFigure() override;
};