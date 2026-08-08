#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 10;
int n, min_x = N, min_y = N, max_x = 0 - N, max_y = 0 - N;
int main() {
	freopen("lab.in", "r", stdin);
	freopen("lab.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		min_x = min(min_x, x);
		min_y = min(min_y, y);
		max_x = max(max_x, x);
		max_y = max(max_y, y);
	}
	cout << min_x - 1 << " " << min_y - 1 << endl << max_x + 1 << " " << max_y + 1;
	return 0;
}
