#include "vector.h"

#include <cstring>

Vector::Vector(size_t size) {
	assert(size != 0);
	m_size = size;
	m_vec.resize(size, 0);
}

Vector::Vector(const Vector & vec) {
	m_size = vec.m_size;
	m_vec = vec.m_vec;
}
