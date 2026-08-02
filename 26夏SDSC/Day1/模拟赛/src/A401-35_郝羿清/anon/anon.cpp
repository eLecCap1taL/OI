#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int n, k;
int a[MAXN][MAXN], f[MAXN][MAXN];

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int main() {
	freopen("anon.in", "r", stdin);
	freopen("anon.out", "w", stdout);
	n = read(), k = read();
	int maxa = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = read();
			maxa = max(maxa, a[i][j]);
		}
	}
	if (k == 2) {
		for (int i = 1; i <= n; i++) f[i][n] = 1, f[1][i] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < n; j++) {
				int t1 = max(max(a[i][j], a[i][j + 1]), max(a[i + 1][j], a[i + 1][j + 1]));
				int t2 = min(min(a[i][j], a[i][j + 1]), min(a[i + 1][j], a[i + 1][j + 1]));
				if ((a[i][j] != t1 && a[i][j] != t2) || (a[i][j + 1] != t1 && a[i][j + 1] != t2) || (a[i - 1][j] != t1 && a[i + 1][j] != t2) || (a[i + 1][j + 1] != t1 && a[i + 1][j + 1] != t2)) {
					f[i][j] = 1;
				}
				else f[i][j] = 2;
			}
		}
	}
	else if (maxa <= 2) {
		if (k == 1) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					f[i][j] = 1;
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					f[i][j] =  n - max(i, j) + 1;
				}
			}
		}
	}
	else {
		set<int>g;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int ans = 0;
				for (int ii = 1; ii <= n - max(i, j) + 1; ii++) {
					for (int jj = 1; jj <= ii; jj++) g.emplace(a[i + ii - 1][j + jj - 1]), g.emplace(a[i + jj - 1][j + ii - 1]);
					if (g.size() <= k) f[i][j] = max(f[i][j], ii);
					else {
						break;
					}
				}
				g.clear();
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << f[i][j] << ' ';
		}
		cout << '\n';
	}
}
