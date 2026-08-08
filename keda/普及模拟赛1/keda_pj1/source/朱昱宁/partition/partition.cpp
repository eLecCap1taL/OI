#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[210], ans;
bool flag[210];
void f(int now) {
	if (now > n) {
		int ha = 0, hb = 0;
		for (int i = 1; i <= n; ++i) {
			if (flag[i])
				ha |= a[i];
			else
				hb |= a[i];
		}
		if (ha == hb)
			ans = (ans + 1) % mod;
		return;
	}
	f(now + 1);
	flag[now] = true;
	f(now + 1);
	flag[now] = false;
}
int main() {
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	f(1);
	cout << ans;
	return 0;
}
