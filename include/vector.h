#pragma once

#include "utils.h"

#include <cassert>

class Vector {
	
	size_t m_size;
	std::vector<int8_t> m_vec;
	
public:
	
	Vector(size_t size);
	Vector(const Vector & vec);
	~Vector() = default;
	
	inline void set(int8_t val, size_t pos) {
		if (pos >= m_size) {
			return;
		}
		
		m_vec[pos] = val;
	}
	
	inline void set(size_t index, int8_t val) {
		assert(m_size >= index);
		m_vec[index] = val;
	}
	
	inline int8_t at(size_t index) const {
		assert(m_size >= index);
		return m_vec[index];
	}
	
	inline Vector operator-(const Vector & vec) const {
		assert(vec.m_size == m_size);
		
		Vector res(m_size);
		for (size_t i = 0; i < m_size; ++i) {
			res.set(i, Utils::abs((m_vec[i] - vec.at(i)) % Utils::TWO));
		}
		
		return res;
	}
	
	inline Vector operator*(const Vector & vec) const {
		assert(m_size == vec.m_size);
		
		Vector res(m_size);
		for (size_t i = 0; i < m_size; ++i) {
			res.set(i, m_vec[i] * vec.at(i));
		}
		
		return res;
	}
	
	inline Vector operator!() const {
		Vector res(m_size);
		for (size_t i = 0; i < m_size; ++i) {
			res.set(i, !m_vec[i]);
		}
		
		return res;
	}
	
	inline int8_t dot(const Vector & vec) const {
		assert(vec.m_size == m_size);
		
		int8_t res = 0;
		for (size_t i = 0; i < m_size; ++i) {
			res += m_vec[i] * vec.at(i);
		}
		
		return Utils::abs(res % Utils::TWO);
	}
	
};
