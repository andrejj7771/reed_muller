#include "reed_muller.h"

ReedMuller::ReedMuller(int8_t r, int8_t m) {
	m_r = r;
	m_m = m;
	
	size_t n = 1 << m;
	size_t k = Utils::sumofCombinations(r, m);
	
	Matrix tmp(k, n);
	
	for (size_t i = 0; i < n; ++i) {
		tmp.at(0, i) = 1;
	}
	
	
}

void ReedMuller::init() {
	
}

