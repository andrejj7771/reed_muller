#include "reed_muller.h"

#include <cstdio>

ReedMuller::ReedMuller(int8_t r, int8_t m) {
	m_r = r;
	m_m = m;
	
	m_k = Utils::sumOfCombinations(m_r, m_m, m_combinations);
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
	size_t pos = 0;
	for (size_t k = 0; k < m_combinations.size(); ++k) {
		const Utils::Vec2D & combs = m_combinations.at(k);
		if (pos == 0) {
			pos = combs.size() - 1;
		}
		
		for (size_t i = 0; i < combs.size(); ++i, ++pos) {
			const std::vector<int> comb = combs.at(i);
			size_t ind_i = static_cast<size_t>(comb.at(0));
			Vector vec(mat.at(ind_i));
			for (size_t j = 1; j < comb.size(); ++j) {
				size_t ind_j = static_cast<size_t>(comb.at(j));
				vec = vec * mat.at(ind_j);
			}
			
			mat.set(pos, vec);
		}
	}
	
#ifdef __DEBUG
	for (size_t i = m_m + 1; i < m_k; ++i) {
		for (size_t j = 0; j < (1 << m_m); ++j) {
			printf("%d ", static_cast<int>(mat.at(i, j)));
		}
		
		printf("\n");
	}
	
	printf("\n");
#endif
	
}
