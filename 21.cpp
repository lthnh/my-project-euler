#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
	int res = 0;
	int A = 0, B = 0;
	if (a > b) {
		A = a;
		B = b;
	} else {
		A = b;
		B = a;
	}
	int r = A % B;
	while (r) {
		A = B;
		B = r;
		r = A % B;
	}
	res = B;
	return res;
}

vector<int> factrz(int a) {
	vector<int> res;
	while (a % 2 == 0) {
		res.push_back(2);
		a /= 2;
	}
	for (int d = 3; d * d < a; d += 2) {
		while (a % d == 0) {
			res.push_back(d);
			a /= d;
		}
	}
	if (a > 1)
		res.push_back(a);
	return res;
}

vector<int> dvsr(vector<int> factors) {
	vector <int> res;
	set<int> uniq_factr(factors.begin(), factors.end());
	return res;
}

int main() {
	vector<int> factrs = factrz(4325);
	dvsr(factrs);
	for (int elem: factrs)
		cout << elem << endl;
	cout << gcd(12, 8) << endl;
	return 0;
}

