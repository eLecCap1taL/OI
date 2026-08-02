#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int N = 3e5 + 10, MD = 998'244'353;
using ll = long long;
ll f[N][2];
vector<pair<int, int>> e[N];
inline void dfs(int u, int fa, int w) {
    sort(e[u].begin(), e[u].end(),
         [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });
    for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i].first == fa) {
            e[u].erase(e[u].begin() + i);
            break;
        }
    }
    bool le = 1;
    for (auto [v, w] : e[u]) {
        if (v == fa) continue;
        le = 0;
        dfs(v, u, w);
    }
    if (le) {
        f[u][0] = f[u][1] = 1;
        return;
    }
    int p;
    for (p = 0; p < e[u].size(); p++) {
        if (e[u][p].second > w) break;
    }
    vector<ll> sp0 = {1}, ss1 = {1};
    for (int i = 0; i < e[u].size(); i++) sp0.push_back(sp0.back() * f[e[u][i].first][0] % MD);
    for (int i = e[u].size() - 1; i >= 0; i--) ss1.push_back(ss1.back() * f[e[u][i].first][1] % MD);
    // 0=指入 1=指出
    // cout << e[u].size() << " " << p << endl;
    // for (auto [v, w] : e[u]) cout << v << " " << w << " | ";
    // for (auto x : ss1) cout << x << " ";
    for (int i = 0; i <= p; i++) f[u][0] += sp0[i] * ss1[e[u].size() - i] % MD;
    for (int i = p; i <= e[u].size(); i++) f[u][1] += sp0[i] * ss1[e[u].size() - i] % MD;
    f[u][1] %= MD;
    f[u][0] %= MD;
}
int main() {
    freopen("soyo.in", "r", stdin);
    freopen("soyo.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    dfs(1, 0, 0);
    cout << f[1][1] << endl;
}