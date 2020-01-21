//#include <iostream>

//#include "reed_muller.h"

//bool test_matrix_construction() {
//	std::printf("test_%s: ", __FUNCTION__);
//	Matrix m(4, 4);
	
//	for (int i = 0; i < 4; ++i) {
//		for (int j = 0; j < 4; ++j) {
//			m.at(i, j) = 1;
//		}
//	}
	
//	for (int i = 0; i < 4; ++i) {
//		for (int j = 0; j < 4; ++j) {
//			if (m.at(i, j) != 1) {
//				return false;
//			}
//		}
//	}
	
//	return true;
//}

//void combination(int n, int m) {
//	std::vector<int> vec;
//	for (int i = 0; i < m; ++i) {
//		vec.push_back(i);
//	}
	
//	while(true) {
//		for (int i = m - 1; i >= 0; --i) {
//			vec[i] = vec[i] + 1;
//		}
//	}

////	for (size_t i = m - 1; i >= 0; --i) {
////		if (vec.at(i) <= n + i - m) {
////			if (i < m) {
////				for (size_t j = i; j < m; ++j) {
////					vec.at(j) = vec.at(j - 1) + 1;
////				}
////			} else if (i == 1) {
////				return;
////			}
////		}
////	}
//}

//int main() {
//	std::cout << test_matrix_construction() << std::endl;
	
//	combination(4, 2);
	
//	ReedMuller rm(3, 4);
	
//	return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

bool NextSet(std::vector<int> & a, int n, int m) {
	int k = m;
	for (int i = k - 1; i >= 0; --i)
		if (a[i] < n - k + i + 1) 
		{
			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return true;
		}
	return false;
}
void Print(std::vector<int> & a, int n) {
	static int num = 1; 
	cout.width(3);
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

using Vec2D = std::vector<std::vector<int>>;


int main() {
	int n, m;
	Vec2D comb_mat;
	
	std::vector<int> a;
	
	cout << "N = ";
	cin >> n;
	cout << "M = ";
	cin >> m;
	
	for (int i = 0; i < n; i++)
		a.push_back(i + 1);
	Print(a, m);
	if (n >= m)
	{
		while (NextSet(a, n, m))
			Print(a, m);
	}
	cin.get(); cin.get();
	return 0;
}
