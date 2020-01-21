#pragma once

#include "utils.h"
#include "matrix.h"

#include <string>

class ReedMuller {
	
	int8_t m_r;
	int8_t m_m;
	uint64_t m_k;
	
	Matrix * m_G;
	Utils::Vec3D m_combinations;
	
public:
	
	ReedMuller(int8_t r, int8_t m);
	~ReedMuller();
	
	inline std::string encode(const std::string & message) {
		std::string code = "";
		
		Vector mess_vec(message.size());
		for (size_t i = 0; i < message.size(); ++i) {
			mess_vec.set(i, message.at(i));
		}
		const Matrix & trG = m_G->transpose();
		for (size_t i = 0; i < (1 << m_m); ++i) {
			int8_t pseudo_bit = mess_vec.dot(trG.at(i));
			code += pseudo_bit + '0';
		}
		
		return code;
	}
	
	inline void decode() {
		
	}
	
private:
	
	void init_V0_V4(Matrix & mat);
	void init_V5_VN(Matrix & mat);
	
};
