#include "catch2/catch_all.hpp"
#include "figures/Rectangle.h"
#include "figures/Triangle.h"

TEST_CASE("Triangle constructor orders parameters")
{
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
		Figure* second = first.clone();

		REQUIRE(first == *dynamic_cast<Triangle*>(second));
}

TEST_CASE("Triangle parameter is calculated correctly") {
	Triangle tri(1, 2, 3.5);
	double result = tri.perimeter();
	double expected = 1 + 2 + 3.5;

	REQUIRE_THAT(result, Catch::Matchers::WithinRel(expected, 0.001));
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
	Figure* second = first.clone();

	REQUIRE(first == *dynamic_cast<Rectangle*>(second));
}

TEST_CASE("Rectangle parameter is calculated correctly") {
	Rectangle rec(1, 2.5);
	double result = rec.perimeter();
	double expected = 1 + 2.5;

	REQUIRE_THAT(result, Catch::Matchers::WithinRel(expected, 0.001));
}