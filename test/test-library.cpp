#include <corecrt_math_defines.h>
#include "catch2/catch_all.hpp"
#include "figures/Circle.h"
#include "figures/FigureFactory.h"
#include "figures/Rectangle.h"
#include "figures/Triangle.h"
#include <memory>
#include "figures/StreamFigureFactory.h"
#include <fstream>
#include <figures/FigureFactoryFactory.h>
	
TEST_CASE("Triangle constructor orders parameters") {
	Triangle first(1, 2, 3);
	Triangle second(2, 3, 1);
	Triangle third(3, 1, 2);

	REQUIRE((first == second && first == third));
}

void createTri(double a, double b, double c) {
	Triangle tri(a, b, c);
}

TEST_CASE("Triangle constructor throws on invalid arg") {
	SECTION("0 arg") {
		REQUIRE_THROWS_AS(createTri(1,0,2), std::invalid_argument);
	}
	SECTION("negative arg") {
		REQUIRE_THROWS_AS(createTri(1, -1, 2), std::invalid_argument);
	}
}

TEST_CASE("Triangle == works correctly")
{
	SECTION("different triangles") {
		Triangle first(1, 2, 3);
		Triangle second(5, 6, 6);

		REQUIRE(!(first == second));
	}
	SECTION("same triangles") {
		Triangle first(1, 2, 3);
		Triangle second(1, 2, 3);

		REQUIRE(first == second);
	}
}

TEST_CASE("Triangle clone works correctly")
{
		Triangle first(1, 2, 3);
		std::unique_ptr<Figure> second = first.clone();

		REQUIRE(first == *dynamic_cast<Triangle*>(second.get()));
}

TEST_CASE("Triangle parameter is calculated correctly") {
	Triangle tri(1, 2, 3.5);
	double result = tri.perimeter();
	double expected = 1 + 2 + 3.5;

	REQUIRE_THAT(result, Catch::Matchers::WithinRel(expected, 0.001));
}

TEST_CASE("Triangle toString works correctly") {
	Triangle tri(1, 2, 3.5);

	REQUIRE(tri.ToString() == "triangle 1 2 3.5");
}

TEST_CASE("Rectangle constructor orders parameters")
{
	Rectangle first(1, 2);
	Rectangle second(2, 1);


	REQUIRE(first == second);
}

void createRec(double a, double b) {
	Rectangle tri(a, b);
}

TEST_CASE("Rectangle constructor throws on invalid arg") {
	SECTION("0 arg") {
		REQUIRE_THROWS_AS(createRec(1, 0), std::invalid_argument);
	}
	SECTION("negative arg") {
		REQUIRE_THROWS_AS(createRec(1, -1), std::invalid_argument);
	}
}

TEST_CASE("Rectangle == works correctly")
{
	SECTION("different rectangles") {
		Rectangle first(1, 2);
		Rectangle second(5, 6);

		REQUIRE(!(first == second));
	}
	SECTION("same rectangles") {
		Rectangle first(1, 2);
		Rectangle second(1, 2);

		REQUIRE(first == second);
	}
}

TEST_CASE("Rectangle clone works correctly")
{
	Rectangle first(1, 2);
	std::unique_ptr<Figure> second = first.clone();

	REQUIRE(first == *dynamic_cast<Rectangle*>(second.get()));
}

TEST_CASE("Rectangle parameter is calculated correctly") {
	Rectangle rec(1, 2.5);
	double result = rec.perimeter();
	double expected = 1 + 2.5;

	REQUIRE_THAT(result, Catch::Matchers::WithinRel(expected, 0.001));
}

TEST_CASE("Rectangle toString works correctly") {
	Rectangle rec(1, 3.5);

	REQUIRE(rec.ToString() == "rectangle 1 3.5");
}


void createCircle(double r) {
	Circle circle(r);
}

TEST_CASE("Circle constructor throws on invalid arg") {
	SECTION("0 arg") {
		REQUIRE_THROWS_AS(createCircle(0), std::invalid_argument);
	}
	SECTION("negative arg") {
		REQUIRE_THROWS_AS(createCircle(-1), std::invalid_argument);
	}
}

TEST_CASE("Circle == works correctly")
{
	SECTION("different circles") {
		Circle first(1);
		Circle second(2);

		REQUIRE(!(first == second));
	}
	SECTION("same circles") {
		Circle first(1);
		Circle second(1);

		REQUIRE(first == second);
	}
}

TEST_CASE("Circle clone works correctly")
{
	Circle first(1);
	std::unique_ptr<Figure> second = first.clone();

	REQUIRE(first == *dynamic_cast<Circle*>(second.get()));
}

TEST_CASE("Circle parameter is calculated correctly") {
	Circle rec(2.5);
	double result = rec.perimeter();
	double expected = 2 * M_PI * 2.5;

	REQUIRE_THAT(result, Catch::Matchers::WithinRel(expected, 0.001));
}

TEST_CASE("Circle toString works correctly") {
	Circle circle( 3.5);

	REQUIRE(circle.ToString() == "circle 3.5");
}

TEST_CASE("Polymorphic == for figure") {

}

TEST_CASE("Figure factory from string") {
	SECTION("create triangle") {
		auto tri = FigureFactory::createFigureFromStr("triangle 1 2 3.5");
		Triangle expected(1, 2, 3.5);
		REQUIRE(expected == *dynamic_cast<Triangle*>(tri.get()));
	}
	SECTION("create rectangle") {
		auto rec = FigureFactory::createFigureFromStr("rectangle 1 2");
		Rectangle expected(1, 2);
		REQUIRE(expected == *dynamic_cast<Rectangle*>(rec.get()));
	}
	SECTION("create triangle") {
		auto circle = FigureFactory::createFigureFromStr("circle 1");
		Circle expected(1);
		REQUIRE(expected == *dynamic_cast<Circle*>(circle.get()));
	}
}

TEST_CASE("Figure factory throws on invalid input") {
	SECTION("invalid figure") {
		REQUIRE_THROWS_AS(FigureFactory::createFigureFromStr("luffy 2 2 2"), std::invalid_argument);
	}
	SECTION("not enough sides tri") {
		REQUIRE_THROWS_AS(FigureFactory::createFigureFromStr("triangle 2 2 "), std::invalid_argument);
	}
	SECTION("not enough sides tri 2") {
		REQUIRE_THROWS_AS(FigureFactory::createFigureFromStr("triangle  "), std::invalid_argument);
	}
	SECTION("not enough sides rec") {
		REQUIRE_THROWS_AS(FigureFactory::createFigureFromStr("rectangle 2 "), std::invalid_argument);
	}
	SECTION("not enough sides rec 2") {
		REQUIRE_THROWS_AS(FigureFactory::createFigureFromStr("rectangle  "), std::invalid_argument);
	}
	SECTION("not radius") {
		REQUIRE_THROWS_AS(FigureFactory::createFigureFromStr("circle "), std::invalid_argument);
	}
}


TEST_CASE("Stream figure factory") {
	SECTION("create triangle") {
		std::stringstream ss("triangle 1 2 3.5");

		std::unique_ptr<FigureFactory> factory = std::make_unique<StreamFigureFactory>(StreamFigureFactory(ss));

		auto tri = factory.get()->createFigure();
		Triangle expected(1, 2, 3.5);
		REQUIRE(expected == *dynamic_cast<Triangle*>(tri.get()));
	}
	SECTION("create rectangle") {
		std::stringstream ss("rectangle 1 2");

		std::unique_ptr<FigureFactory> factory = std::make_unique<StreamFigureFactory>(StreamFigureFactory(ss));

		auto rec = factory.get()->createFigure();
		Rectangle expected(1, 2);
		REQUIRE(expected == *dynamic_cast<Rectangle*>(rec.get()));
	}
	SECTION("create circle") {
		std::stringstream ss("circle 1");

		std::unique_ptr<FigureFactory> factory = std::make_unique<StreamFigureFactory>(StreamFigureFactory(ss));

		auto circle = factory.get()->createFigure();
		Circle expected(1);
		REQUIRE(expected == *dynamic_cast<Circle*>(circle.get()));
	}
}

TEST_CASE("Abstract factory") {
	SECTION("creates stream factory that works") {
		std::ofstream os("C:\\Users\\Ivan Bukev\\source\\repos\\Figures---design-patterns-hw3\\src\\test.txt");
		os << "triangle 2.1 2.3 3.1\ncircle 1.1";
		os.close();

		std::stringstream ss("test.txt");
		auto fac = FigureFactoryFactory::create("file", ss);
		auto tri = fac.get()->createFigure();
		auto circle = fac.get()->createFigure();
		REQUIRE((tri->ToString() == "triangle 2.1 2.3 3.1" && circle->ToString() == "circle 1.1"));
	}
}

