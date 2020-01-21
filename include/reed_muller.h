#pragma once

#include "utils.h"
#include "matrix.h"

class ReedMuller {
	
	int8_t m_r;
	int8_t m_m;
	
	Matrix * m_G;
	
public:
	
	ReedMuller(int8_t r, int8_t m);
	~ReedMuller();
	
private:
	
	void init();
	
};
