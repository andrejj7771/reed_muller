#include "matrix.h"

Matrix::Matrix(size_t r, size_t c) {
	m_rows = r;
	m_cols = c;
	
	for (size_t i = 0; i < r; ++i) {
		m_mat.push_back(Vector(c));
	}
}

Matrix::Matrix(const Matrix & mat) {
	m_rows = mat.m_rows;
	m_cols = mat.m_cols;
	
	for (size_t i = 0; i < m_rows; ++i) {
		m_mat.push_back(Vector(mat.at(i)));
	}
}
