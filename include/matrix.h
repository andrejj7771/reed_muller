#pragma once

#include "vector.h"

using MatPrivate = std::vector<Vector>;

class Matrix {
	
	size_t m_rows;
	size_t m_cols;
	
	MatPrivate m_mat;
	
public:
	
	Matrix(size_t r, size_t c);
	Matrix(const Matrix & mat);
	~Matrix() = default;
	
	inline Matrix transpose() const {
		Matrix res(m_cols, m_rows);
		
		for (size_t i = 0; i < m_rows; ++i) {
			for (size_t j = 0; j < m_cols; ++j) {
				res.set(j, i, m_mat[i].at(j));
			}
		}
		
		return res;
	}
	
	inline void set(size_t r, size_t c, int8_t val) {
		assert(m_rows != r);
		m_mat[r].set(c, val);
	}
	
	inline int8_t at(size_t r, size_t c) const {
		return m_mat[r].at(c);
	}
	
	inline const Vector & at(size_t r) const {
		return m_mat.at(r);
	}
	
	inline void set(size_t r, const Vector & vec) {
		assert(m_rows != r);
		m_mat[r] = vec;
	}
	
	inline size_t getNumOfRows() const {
		return m_rows;
	}
	
	inline size_t getNumOfCols() const {
		return m_cols;
	}
	
};

