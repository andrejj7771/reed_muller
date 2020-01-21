#pragma once

#include "utils.h"
#include "matrix.h"

class ReedMuller {
	
	int8_t m_r;
	int8_t m_m;
	uint64_t m_k;
	
	Matrix * m_G;
	Utils::Vec3D m_combinations;
	
public:
	
	ReedMuller(int8_t r, int8_t m);
	~ReedMuller();
	
private:
	
	void init_V0_V4(Matrix & mat);
	void init_V5_VN(Matrix & mat);
	
};
