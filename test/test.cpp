#include <catch2/catch_test_macros.hpp>

#include <random>

#include <geometry.h>
#include <delaunay.h>

// Generate n points within a circle of the given radius
std::vector<point> generate_points(int n, float radius) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0.0, 1.0);

	std::vector<point> result;

	while(n--) {
		float r = dist(gen) * radius;
		float theta = dist(gen) * 2 * M_PI;

		result.emplace_back(r * cos(theta), r * sin(theta));
	}

	return result;
}

// Simplest check for testing; ensure that no point is within any circumcircle
bool valid_triangulation(std::vector<point> points) {
	std::vector<triangle> triangulation = delaunay::triangulate(points);

	for(triangle& t : triangulation) {
		circle circumcircle = t.circumcircle();

		for(point& p : points) {
			if(circumcircle.contains(p)) {
				return false;
			}
		}
	}

	return true;
}

TEST_CASE("Nearly collinear points are triangulated", "[collinear]") {
	std::vector<point> points = {
	    point(0.0422123, 0.608088),
		point(0.0326503, -0.388441),
		point(-0.0545815, 0.166688)
    };

	REQUIRE(delaunay::triangulate(points).size() == 1);

	points = {
	    point(0.286269, -0.615398),
		point(0.262937, -0.6643),
		point(0.56914, -0.0624119)
    };

	REQUIRE(delaunay::triangulate(points).size() == 1);

	points = {
	    point(0.25, 0.25),
		point(0.35, 0.35),
		point(0.45, 0.45005)
    };

	REQUIRE(delaunay::triangulate(points).size() == 1);
}

TEST_CASE("Collinear points have no triangulation", "[collinear]") {
	std::vector<point> horizontal_line = {
	    point(0.0, 1.0),
		point(0.5, 1.0),
		point(1.5, 1.0)
    };

	REQUIRE(delaunay::triangulate(horizontal_line).size() == 0);

	std::vector<point> vertical_line = {
	    point(0.0, -5.0),
		point(0.0, 0.0),
		point(0.0, 10.0)
    };

	REQUIRE(delaunay::triangulate(vertical_line).size() == 0);
}

TEST_CASE("Random points are triangulated", "[random]") {
	REQUIRE(valid_triangulation(generate_points(25, 10)));
	REQUIRE(valid_triangulation(generate_points(50, 10)));
	REQUIRE(valid_triangulation(generate_points(100, 25)));
	REQUIRE(valid_triangulation(generate_points(1000, 100)));
	REQUIRE(valid_triangulation(generate_points(5000, 500)));
}
