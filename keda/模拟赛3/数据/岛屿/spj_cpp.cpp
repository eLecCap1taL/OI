#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>

const long double EPS = 1e-8;

int main() {
	std::ifstream fin("input");
	std::ifstream fout("user_out");
	std::ifstream fans("answer");

	long double ans, out;

	fans >> ans;
	if (!(fout >> out)) {
		std::cerr << "Can't read the number" << std::endl;
		std::cout << 0 << std::endl;
		exit(0);
	}
	if (fabs(out - ans) > EPS && fabs(out - ans) / fabs(ans + EPS) > EPS) {
		std::cout << 0 << std::endl;
		exit(0);
	}

	std::cout << 100 << std::endl;
}
