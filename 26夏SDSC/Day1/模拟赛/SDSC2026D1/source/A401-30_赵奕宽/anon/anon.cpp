#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int cnt[501][501][501];
int f[502][502];
int a[501][501];
int ans[501][501];
bool apr[501];

int main() {
	freopen("anon.in", "r", stdin);
	freopen("anon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            apr[a[i][j]] = true;
        }
    for (int c = 1; c <= n; ++c) if (apr[c]) {
        for (int i = 1; i <= n + 1; ++i) f[i][n + 1] = inf;
        for (int j = 1; j <= n + 1; ++j) f[n + 1][j] = inf;

        for (int i = n; i >= 1; --i) {
            for (int j = n; j >= 1; --j) {
                if (a[i][j] == c) {
                    f[i][j] = 1;
                } else {
                    int m = f[i + 1][j];
                    if (f[i][j + 1] < m) m = f[i][j + 1];
                    if (f[i + 1][j + 1] < m) m = f[i + 1][j + 1];
                    f[i][j] = (m >= inf ? inf : m + 1);
                }
            }
        }

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (f[i][j] <= n)
                    ++cnt[i][j][f[i][j]];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int m = min(n - i + 1, n - j + 1);
            int sum = 0;
            int res = m;
            for (int v = 1; v <= m; ++v) {
                sum += cnt[i][j][v];
                if (sum > k) {
                    res = v - 1;
                    break;
                }
            }
            ans[i][j] = res;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
