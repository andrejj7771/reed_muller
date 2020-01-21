#pragma once

#include <cstdint>
#include <cstddef>

namespace Utils {

	static const int8_t TWO = 2;
	
	int8_t abs(int8_t value);
	
	uint64_t factorial(int8_t num);
	uint64_t combination(int8_t by, int8_t from);
	uint64_t sumofCombinations(int8_t r, int8_t m);
	
}
