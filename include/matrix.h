#pragma once

#include "vector.h"

class Matrix {
	
	size_t m_rows;
	size_t m_cols;
	
	Vector ** m_mat;
	
public:
	
	Matrix(size_t r, size_t c);
	Matrix(const Matrix & mat);
	~Matrix();
	
	inline Matrix transpose() const {
		Matrix res(m_cols, m_rows);
		
		for (size_t i = 0; i < m_rows; ++i) {
			for (size_t j = 0; j < m_cols; ++j) {
				res.at(j, i) = m_mat[i]->at(j);
			}
		}
		
		return res;
	}
	
	inline int8_t & at(size_t r, size_t c) const {
		return m_mat[r]->at(c);
	}
	
	inline Vector & at(size_t r) const {
		return *m_mat[r];
	}
	
};

