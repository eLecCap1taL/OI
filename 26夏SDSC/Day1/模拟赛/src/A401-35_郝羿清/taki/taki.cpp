#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
int a[MAXN], tot = 0;

int main() {
	freopen("taki.in", "r", stdin);
	freopen("taki.out", "w", stdout);
	int k, q;
	int ans = 0;
	cin >> k >> q;
	for (int i = 1; i <= k; i++) {
		int t;
		cin >> t;
		while(t--) {
			cin >> a[++tot];
		}
	}
	sort(a + 1, a + tot + 1, greater<>());
	for (int i = 1; i <= tot; i ++) {
		a[i] = a[i] + a[i - 1];
	}
	cout << a[tot] << '\n';
}
