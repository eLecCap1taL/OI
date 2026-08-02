#include <iostream>

using std::cin;
using std::cout;
const int N = 1e6 + 10;

int b[N];

int main()
{
	freopen("tomori.in", "r", stdin);
	freopen("tomori.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	if (n == 1)
		cout << b[1] << '\n';
	else if (n == 2)
		cout << 1ll * (b[1] + b[2]) * 499122177 % 998244353 << '\n';
	return 0;
}
