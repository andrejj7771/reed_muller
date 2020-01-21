#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>

namespace Utils {

	static const int8_t TWO = 2;
	using Vec2D = std::vector<std::vector<int>>;
	using Vec3D = std::vector<Vec2D>;
	
	int8_t abs(int8_t value);
	
	uint64_t factorial(int8_t num);
	uint64_t numOfCombinations(int8_t by, int8_t from);
	uint64_t sumOfCombinations(int8_t r, int8_t m, Vec3D & combination);
	
	bool combination(std::vector<int> & a, int n, int m);
	Vec2D combinationList(int n, int m);
	
}
