#pragma once

#include <cstdint>
#include <cstddef>

namespace Utils {

	static const int8_t TWO = 2;
	
	int8_t abs(int8_t value) {
		//WARNING: be careful
		return value < 0 ? -value : value;
	}
	
	uint64_t factorial(int8_t num) {
		if (num == 2) {
			return 2;
		}
		
		return static_cast<uint64_t>(num) * factorial(num - 1);
	}
	
	uint64_t combination(int8_t by, int8_t from) {
		uint64_t res = factorial(from) / factorial(by) * factorial(from - by);
		
		return res;
	}
	
	uint64_t sumofCombinations(int8_t r, int8_t m) {
		uint64_t sum = 1;
		
		for (int8_t i = 1; i <= r; ++i) {
			sum += combination(i, m);
		}
		
		return sum;
	}
	
}
