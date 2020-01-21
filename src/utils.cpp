#include "utils.h"

namespace Utils {
	
	int8_t abs(int8_t value) {
		//WARNING: be careful
		return value < 0 ? -value : value;
	}
	
	uint64_t factorial(int8_t num) {
		if (num == 0 || num == 1) {
			return 1;
		} else if (num == 2) {
			return 2;
		}
		
		return static_cast<uint64_t>(num) * factorial(num - 1);
	}
	
	uint64_t numOfCombinations(int8_t by, int8_t from) {
		uint64_t res = factorial(from) / (factorial(by) * factorial(from - by));
		
		return res;
	}
	
	uint64_t sumOfCombinations(int8_t r, int8_t m) {
		uint64_t sum = 1;
		
		for (int8_t i = 1; i <= r; ++i) {
			sum += numOfCombinations(i, m);
		}
		
		return sum;
	}
	
	bool combination(std::vector<int> & a, int n, int m) {
		int k = m;
		for (int i = k - 1; i >= 0; --i) {
			if (a[i] < int(size_t(n - k) + i + 1)) {
				++a[i];
				for (int j = i + 1; j < k; ++j)
					a[j] = a[j - 1] + 1;
				return true;
			}
		}
		return false;
	}
	
	Vec2D combinationList(int n, int m) {
		Vec2D combMatrix;
		std::vector<int> combVec;
		
		for (int i = 0; i < m; ++i) {
			combVec.push_back(i + 1);
		}
		
		combMatrix.push_back(combVec);
		
		for (int i = 1; i < m; ++i) {
			if (n >= m) {
				while (combination(combVec, n, i) == true) {
					combMatrix.push_back(combVec);
				}
			}
		}
		
		return combMatrix;
	}
	
}
