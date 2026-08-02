#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;

int n;
vector<vector<pair<int, int>>> g;
struct E { int u, v, rU, rV; };
vector<E> e;
vector<vector<int>> p, s;

void f(int v, int fa) {
    int m = 0;
    vector<int> c, r, a, b;
    for (pair<int, int> &pr : g[v]) {
        int w = pr.first;
        int id = pr.second;
        int to = e[id].u ^ e[id].v ^ v;
        if (to == fa) continue;
        f(to, v);
        c.push_back(to);
        r.push_back(v == e[id].u ? e[id].rU : e[id].rV);
        a.push_back(p[to][to == e[id].u ? e[id].rU : e[id].rV]);
        b.push_back(s[to][to == e[id].u ? e[id].rU : e[id].rV]);
        m++;
    }
    int d = m + (fa == 0 ? 0 : 1);
    vector<int> o(m);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int i, int j) { return r[i] < r[j]; });
    vector<int> x(m + 1), y(m + 1);
    x[0] = 1;
    for (int i = 0; i < m; i++) x[i + 1] = 1LL * x[i] * a[o[i]] % M;
    y[m] = 1;
    for (int i = m - 1; i >= 0; i--) y[i] = 1LL * y[i + 1] * b[o[i]] % M;
    vector<int> dp(d + 1);
    int t = 0;
    for (int k = 0; k <= d; k++) {
        if (t < m && r[o[t]] == k) t++;
        dp[k] = 1LL * x[t] * y[t] % M;
    }
    p[v].resize(d + 2);
    s[v].resize(d + 2);
    p[v][0] = 0;
    for (int k = 0; k <= d; k++) p[v][k + 1] = (p[v][k] + dp[k]) % M;
    s[v][d + 1] = 0;
    for (int k = d; k >= 0; k--) s[v][k] = (s[v][k + 1] + dp[k]) % M;
}

int main() {
	freopen("soyo.in", "r", stdin);
	freopen("soyo.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    g.resize(n + 1);
    e.resize(n);
    p.resize(n + 1);
    s.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[i] = {u, v, 0, 0};
        g[u].push_back({i, i});
        g[v].push_back({i, i});
    }
    for (int v = 1; v <= n; v++) {
        sort(g[v].begin(), g[v].end());
        for (int i = 0; i < (int)g[v].size(); i++) {
            int id = g[v][i].second;
            if (e[id].u == v) e[id].rU = i + 1;
            else e[id].rV = i + 1;
        }
    }
    f(1, 0);
    cout << p[1][(int)g[1].size() + 1] << endl;
}
