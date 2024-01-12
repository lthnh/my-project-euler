#include <iostream>

using namespace std;

int main() {
	// 0 1 2
	// 0 1
	// 0 1 2
	int bound_per_elem[3] = {2, 1, 2};
	int d[3] = {0};
	int bound = 0;
	for (size_t i = 0; i < 3; ++i) {
		bound += bound_per_elem[i];
	}
	// generate cartesian product of three sets {0, 1, 2} {0, 1} {0, 1, 2}
	int sum = 0;
	while (sum < bound) {
		size_t i = 0;
		while (i < 3) {
			if (d[i] + 1 <= bound_per_elem[i]) {
				++d[i];
				break;
			} else {
				d[i] = 0;
				++i;
			}
		}

		for (int elem: d) {
			cout << elem << " ";
		}
		cout << endl;

		sum = 0;
		for (size_t i = 0; i < 3; ++i) {
			sum += d[i];
		}
	}
	return 0;
}
