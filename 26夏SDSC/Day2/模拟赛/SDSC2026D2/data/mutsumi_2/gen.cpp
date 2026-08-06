#include <bits/stdc++.h>
using namespace std;

const int HACK[8] = {1, 1, 3, 4, 1, 2, 2, 1};

/* 官方区间 DP，用来算 .ans */
int dp_solve(const vector<int>& a) {
    int n = (int)a.size() - 1;
    const int INF = 1e9;

    vector<vector<int>> f(n + 2, vector<int>(n + 2, INF));

    for (int len = 2; len <= n; len += 2) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;

            if (a[l] > l) continue;
            if ((l - a[l]) & 1) continue;

            int res = (l - a[l]) / 2;

            for (int k = l + 1; k < r; k += 2) {
                if (f[l][k] == INF || f[k + 1][r] == INF) continue;
                f[l][r] = min(f[l][r],
                              max({res, f[l][k], f[k + 1][r] - (k - l + 1) / 2}));
            }

            if (len == 2 || f[l + 1][r - 1] <= res) {
                f[l][r] = min(f[l][r], res);
            }
        }
    }

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        for (int j = i - 2; j >= 0; j -= 2) {
            if (f[j + 1][i] <= dp[j]) {
                dp[i] = max(dp[i], dp[j] + (i - j) / 2);
            }
        }
    }

    return dp[n];
}

/* 最右贪心，只用于验证 hack 一定有效 */
int greedy_solve(const vector<int>& a) {
    vector<int> v;
    for (int i = 1; i < (int)a.size(); ++i) v.push_back(a[i]);

    int ans = 0;
    while (true) {
        int pos = -1;
        for (int i = (int)v.size() - 2; i >= 0; --i) {
            if (v[i] == i + 1) {
                pos = i;
                break;
            }
        }

        if (pos == -1) break;

        v.erase(v.begin() + pos, v.begin() + pos + 2);
        ++ans;
    }

    return ans;
}

vector<int> make_data(int n) {
    int m = n - 8;

    vector<int> a(1, 0);

    for (int i = 1; i <= m; ++i) a.push_back(1);

    for (int x : HACK) a.push_back(m + x);

    return a;
}

int main() {
    vector<int> ns = {
        8, 8, 8, 8, 30, 40, 46, 50, 90, 88,
        92, 96, 94, 100, 400, 480, 560, 640, 720, 800
    };

    for (int id = 1; id <= (int)ns.size(); ++id) {
        int n = ns[id - 1];

        vector<int> a = make_data(n);

        int dp = dp_solve(a);
        int g = greedy_solve(a);

        // 验证：本构造必须让贪心恰好少 1
        if (dp != n / 2 || g != n / 2 - 1) {
            cerr << "构造失败 at test " << id << '\n';
            return 1;
        }

        string inFile = "mutsumi_" + to_string(id) + ".in";
        string ansFile = "mutsumi_" + to_string(id) + ".ans";

        ofstream fin(inFile);
        ofstream fout(ansFile);

        fin << n << '\n';
        for (int i = 1; i <= n; ++i) {
            if (i > 1) fin << ' ';
            fin << a[i];
        }
        fin << '\n';

        fout << dp << '\n';

        cerr << "mutsumi_" << id
             << "  n=" << n
             << "  dp=" << dp
             << "  greedy=" << g << '\n';
    }

    return 0;
}