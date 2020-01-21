#include "matrix.h"

Matrix::Matrix(size_t r, size_t c) {
	m_rows = r;
	m_cols = c;
	
	m_mat = new Vector*[r];
	for (size_t i = 0; i < r; ++i) {
		m_mat[i] = new Vector(c);
	}
}

Matrix::Matrix(const Matrix & mat) {
	m_rows = mat.m_rows;
	m_cols = mat.m_cols;
	
	m_mat = new Vector*[m_rows];
	for (size_t i = 0; i < m_rows; ++i) {
		m_mat[i] = new Vector(mat.at(i));
	}
}

Matrix::~Matrix() {
	for (size_t i = 0; i < m_rows; ++i) {
		delete m_mat[i];
	}
	
	delete [] m_mat;
}

