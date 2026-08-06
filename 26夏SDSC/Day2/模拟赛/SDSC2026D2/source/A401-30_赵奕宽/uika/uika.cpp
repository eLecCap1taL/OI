#include <bits/stdc++.h>
using namespace std;
int a[2000006];

void solve() {
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < m; i ++) {
		cin >> a[i];
	}

	if (n == m) {
		printf("YES\n");
		return ;
	}
	if ((n - m) % (k - 1) != 0) {
		printf("NO\n");
		return ;
	}
	
	int t = (k - 1) / 2;
	bool f = 0;
	for (int i = 0; i < m; i ++) {
		int l = a[i] - i - 1;
		int r = n - a[i] - m + i + 1;
		if (l >= t && r <= t) {
			f = 1;
			break;
		}
	}
	
	if (f) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return ;
}

int main() {
	freopen("uika.in", "r", stdin);
	freopen("uika.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t --) {
		solve();
	}
}
