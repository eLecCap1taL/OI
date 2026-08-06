#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

int rnd(int l, int r) {
    if (l > r) return l;
    return uniform_int_distribution<int>(l, r)(rng);
}

const int INF = 1e9;

/* 官方区间 DP */
int solve(const vector<int>& a) {
    int n = (int)a.size() - 1;

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

/* 最右贪心，只用于验证 hack 是否有效 */
int greedyRight(const vector<int>& a) {
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

/*
  普通生成器中“无用的位置”的填法：
  填成 i+1（最后一个位置填 n-1）。
  这样它们永远不会成为合法的左端点，也不会在拼接 hack 块时产生额外边界操作。
*/
int safeFill(int pos, int n) {
    if (n == 1) return 1;
    if (pos == n) return n - 1;
    return pos + 1;
}

/* 生成一个可完全删除区间 [l, r]，其“需求时间”为 need */
bool genRange(int l, int r, int need, vector<int>& a) {
    int len = r - l + 1;

    if (len <= 0 || (len & 1)) return false;
    if (l - 2 * need < 1) return false;

    if (len == 2) {
        a[l] = l - 2 * need;
        return true;
    }

    for (int attempt = 0; attempt < 50; ++attempt) {
        vector<int> bak = a;
        int mode = rnd(0, 1);

        if (mode == 0) {
            int maxS = len / 2 - 1;
            int s = rnd(1, maxS);
            int k = l + 2 * s - 1;

            int leftNeed = rnd(0, need);

            if (genRange(l, k, leftNeed, a) &&
                genRange(k + 1, r, need + s, a)) {
                return true;
            }
        } else {
            int midNeed = rnd(0, need);

            if (genRange(l + 1, r - 1, midNeed, a)) {
                a[l] = l - 2 * need;
                return true;
            }
        }

        a = bak;
    }

    return false;
}

/* 生成一个答案为 target 的普通数组 */
vector<int> generateArray(int n, int target) {
    vector<int> a(n + 1, 0);

    if (target > 0) {
        if (!genRange(1, 2 * target, 0, a)) return {};
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) a[i] = safeFill(i, n);
    }

    return a;
}

struct Case {
    int n;
    int leftAns;
    bool useHack;
};

int main() {
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    const int HACK[8] = {1, 1, 3, 4, 1, 2, 2, 1};

    vector<Case> cases = {
        // 前 4 个点小数据，不拼 hack
        {5, 1, false},
        {8, 0, false},
        {8, 2, false},
        {8, 3, false},

        // n <= 50
        {50, 2, true},
        {50, 5, true},
        {50, 8, true},
        {50, 12, true},

        // n <= 100
        {100, 5, true},
        {100, 10, true},
        {100, 15, true},
        {100, 20, true},
        {100, 25, true},
        {100, 30, true},

        // n <= 800
        {800, 20, true},
        {800, 50, true},
        {800, 100, true},
        {800, 150, true},
        {800, 200, true},
        {800, 300, true},
    };

    for (int id = 0; id < (int)cases.size(); ++id) {
        const Case& c = cases[id];

        vector<int> whole;
        bool ok = false;

        for (int attempt = 0; attempt < 100; ++attempt) {
            vector<int> a;

            if (c.useHack) {
                int m = c.n - 8;

                vector<int> left = generateArray(m, c.leftAns);
                if (left.empty()) continue;

                a.assign(1, 0);

                for (int i = 1; i <= m; ++i) a.push_back(left[i]);

                // hack 块整体右移 m
                for (int x : HACK) a.push_back(m + x);
            } else {
                a = generateArray(c.n, c.leftAns);
                if (a.empty()) continue;
            }

            int dp = solve(a);

            int expected = c.leftAns + (c.useHack ? 4 : 0);
            if (dp != expected) continue;

            if (c.useHack) {
                int g = greedyRight(a);
                if (!(dp > g)) continue;
            }

            whole = a;
            ok = true;
            break;
        }

        if (!ok) {
            cerr << "Failed to generate case " << id + 1 << '\n';
            return 1;
        }

        int n = (int)whole.size() - 1;
        int dp = solve(whole);

        string inFile = "mutsumi_" + to_string(id + 1) + ".in";
        string ansFile = "mutsumi_" + to_string(id + 1) + ".ans";

        ofstream fin(inFile);
        ofstream fout(ansFile);

        fin << n << '\n';

        for (int i = 1; i <= n; ++i) {
            if (i > 1) fin << ' ';
            fin << whole[i];
        }

        fin << '\n';
        fout << dp << '\n';

        cerr << "mutsumi_" << id + 1
             << "  n=" << n
             << "  dp=" << dp
             << "  greedy=" << (c.useHack ? greedyRight(whole) : -1)
             << '\n';
    }

    return 0;
}