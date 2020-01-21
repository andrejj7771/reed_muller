#include <iostream>

#include "reed_muller.h"

bool test_matrix_construction() {
	std::printf("test_%s: ", __FUNCTION__);
	Matrix m(4, 4);
	
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			m.set(i, j, 1);
		}
	}
	
	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			if (m.at(i, j) != 1) {
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	std::cout << test_matrix_construction() << std::endl;
	
	ReedMuller rm(3, 4);
	
	return 0;
}
