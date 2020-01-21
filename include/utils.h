#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>
#include <map>
#include <string>

namespace Utils {
	
	enum class arg_t : uint8_t {
		path = 0,
		help = 1,
		message = 2,
		r = 3,
		m = 4,
		mode = 5
	};
	
	static const int8_t TWO = 2;
	using Vec2D = std::vector<std::vector<int>>;
	using Vec3D = std::vector<Vec2D>;
	
	int8_t abs(int8_t value);
	
	uint64_t factorial(int8_t num);
	uint64_t numOfCombinations(int8_t by, int8_t from);
	uint64_t sumOfCombinations(int8_t r, int8_t m, Vec3D & combination);
	
	bool combination(std::vector<int> & a, int n, int m);
	Vec2D combinationList(int n, int m);
	
	void printHelp();
	std::map<arg_t, std::string> getArgsList(int argc, char **argv);
	std::vector<std::string> getMessageList(const std::string & messages);
	
}
