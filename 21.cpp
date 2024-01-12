#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

typedef struct factor {
	int prime;
	int exp;
} factor;

vector<factor> factrz(int a) {
	vector<factor> res;
	factor factr = factor {2, 0};
	while (a % 2 == 0) {
		++factr.exp;
		a /= 2;
	}
	if (factr.exp > 0) {
		res.push_back(factr);
	}
	int b = a;
	for (int d = 3; d * d < b; d += 2) {
		if (a % d == 0) {
			factr = factor {d, 0};
			while (a % d == 0) {
				++factr.exp;
				a /= d;
			}
			res.push_back(factr);
		}
	}
	if (a > 1)
		res.push_back(factor {a, 1});
	return res;
}

vector<int> dvsr(vector<factor> const &factors) {
	vector<int> res;

	size_t n_factr = factors.size();
	vector<int> primes(n_factr);
	vector<int> exps(n_factr);
	int bound = 0;
	size_t n_res = 1;

	for (vector<int>::size_type i = 0; i < n_factr; ++i) {
		primes[i] = factors[i].prime;
		exps[i] = factors[i].exp;
		bound += factors[i].exp;
		n_res *= (static_cast<size_t>(factors[i].exp));
	}

	vector<int> exp_combs(n_factr, 0);
	int sum = 0;
	while (sum < bound) {
		size_t i = 0;
		while (i < n_factr) {
			if (exp_combs[i] + 1 <= exps[i]) {
				++exp_combs[i];
				break;
			} else {
				exp_combs[i] = 0;
				++i;
			}
		}

		int prod = 1;
		for (vector<int>::size_type j = 0; j < n_factr; ++j) {
			prod *= static_cast<int>(
					pow(
						static_cast<double>(primes[j]),
						static_cast<double>(exp_combs[j]))
					);
		}
		res.push_back(prod);

		sum = 0;
		for (int exp: exp_combs) {
			sum += exp;
		}
	}
	if (!res.empty()) {
		res.pop_back();
	}
	res.insert(res.begin(), 1);
	if (res.size() > 1) {
		sort(res.begin(), res.end());
	}
	return res;
}

int amicable(int a) {
	vector<factor> factrs = factrz(a);
	vector<int> dvsrs = dvsr(factrs);
	int res = accumulate(dvsrs.begin(), dvsrs.end(), 0);
	return res;
}

int main() {
	int n = 10000;
	int sum = 0;
	bool *check = new bool[static_cast<size_t>(n + 1)] {};
	for (int i = 2; i <= n; ++i) {
		if (!check[static_cast<size_t>(i)]) {
			int am = amicable(i);
			int im = amicable(am);
			if (i == im) {
				cout << am << " " << im << endl;
				if (am <= n && am != i) {
					check[static_cast<size_t>(am)] = true;
					sum += (i + am);
				}
			}
		}
	}
	cout << sum << endl;
	delete[] check;
	return 0;
}

