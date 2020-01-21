#include "reed_muller.h"

#include <cstdio>

ReedMuller::ReedMuller(int8_t r, int8_t m) {
	m_r = r;
	m_m = m;
	
	m_k = Utils::sumOfCombinations(m_r, m_m);
	Matrix tmp(m_k, 1 << m);
	
	init_V0_V4(tmp);
	init_V5_VN(tmp);
	
	m_G = new Matrix(tmp);
}

ReedMuller::~ReedMuller() {
	delete m_G;
}

void ReedMuller::init_V0_V4(Matrix & mat) {
	uint64_t offset = (1 << m_m);
	size_t m = static_cast<size_t>(m_m);
	for (size_t i = 0; i <= m; ++i, offset >>= 1) {
		size_t b_s = offset << 1;
		size_t step = 0;
		for (size_t j = 0; j < (1 << m_m); ++j) {
			size_t k = j - step;
			
			if (k == b_s) {
				k -= b_s;
				step += b_s;
			}
			
			if (k < offset) {
				mat.set(i, j, 1);
			}
		}
	}
	
#ifdef __DEBUG
	printf("\n");
	for (size_t i = 0; i <= m ; ++i) {
		for (size_t j = 0; j < (1 << m_m); ++j) {
			printf("%d ", static_cast<int>(mat.at(i, j)));
		}
		
		printf("\n");
	}
	
	printf("\n");
#endif
	
}
	
void ReedMuller::init_V5_VN(Matrix & mat) {
	Utils::Vec2D combs = Utils::combinationList(m_m, m_r);
	
#ifdef __DEBUG
	printf("\n");
	for (size_t i = m_k - m_m - 1; i < m_k; ++i) {
		for (size_t j = 0; j < (1 << m_m); ++j) {
			printf("%d ", static_cast<int>(mat.at(i, j)));
		}
		
		printf("\n");
	}
	
	printf("\n");
#endif
	
}
