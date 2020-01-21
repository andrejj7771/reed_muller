#include "vector.h"

#include <cstring>

Vector::Vector(size_t size) {
	assert(size == 0);
	m_size = size;
	
	m_vec = new int8_t[size];
	std::memset(m_vec, 0, m_size);
}

Vector::Vector(const Vector & vec) {
	m_size = vec.m_size;
	m_vec = new int8_t[m_size];
	std::memcpy(m_vec, vec.m_vec, m_size);
}

Vector::~Vector() {
	delete [] m_vec;
}
