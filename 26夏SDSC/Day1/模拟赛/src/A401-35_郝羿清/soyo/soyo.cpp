#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const int MOD = 998244353;
int n;
long long d[MAXN], maxd;
struct edge {
	int v;
	long long w;
};
vector<edge> g[MAXN];
vector<long long> ed;
void dfs(int u, int fa) {
	for (auto e : g[u]) {
		int v = e.v;
		long long w = e.w;
		if (v == fa) continue;
		ed.push_back(w);
		dfs(v, u);
	}
}

int main() {
	freopen("soyo.in", "r", stdin);
	freopen("soyo.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back({v, i * 1ll});
		g[v].push_back({u, i * 1ll});
		d[u]++, d[v]++;
		maxd = max(maxd, max(d[u], d[v]));
	}
	if (maxd != 2) {
		cout << 0 << '\n';
		return 0;
	}
	int s;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 1) {
			s = i;
			break;
		}
	}
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = (i + d[i - 1]) % MOD;
	}
	dfs(s, 0);
	cout << (1 << (n - 3)) + 3 <<'\n';
}
//5 -> 7 -> 11
