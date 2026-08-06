#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

int rnd(int l, int r) {
    if (l > r) return l;
    return uniform_int_distribution<int>(l, r)(rng);
}

const int INF = 1e9;

// 官方区间 DP，用于生成正确答案
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

// 生成一个 a[i] > i 的数，保证它永远不会成为可操作位置
int randomGreater(int i, int n) {
    if (i == n) return n;
    return rnd(i + 1, n);
}

// 构造完全可删除区间 [l, r]，其“需求时间”为 need
// 会设置操作者位置的值，其他位置保持 0，稍后填充为安全值
bool genRange(int l, int r, int need, vector<int>& a) {
    int len = r - l + 1;

    if (len <= 0 || len % 2 != 0) return false;
    if (l - 2 * need < 1) return false;

    if (len == 2) {
        a[l] = l - 2 * need;
        return true;
    }

    for (int attempt = 0; attempt < 10; ++attempt) {
        int mode = rnd(0, 1);

        if (mode == 0) {
            // 分治形式：左半 + 右半
            int maxS = len / 2 - 1;
            int s = rnd(1, maxS);
            int k = l + 2 * s - 1;

            int leftNeed = rnd(0, need);

            if (genRange(l, k, leftNeed, a) &&
                genRange(k + 1, r, need + s, a)) {
                return true;
            }
        } else {
            // 包裹形式：先删中间，再删外面
            int midNeed = rnd(0, need);

            if (genRange(l + 1, r - 1, midNeed, a)) {
                a[l] = l - 2 * need;
                return true;
            }
        }
    }

    return false;
}

// 生成一个答案为 ans 的数组
vector<int> generateArray(int n, int ans) {
    vector<int> a(n + 1, 0);

    if (ans > 0) {
        bool ok = genRange(1, 2 * ans, 0, a);
        if (!ok) return {};
    }

    // 所有非操作者位置都设为 a[i] > i
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            a[i] = randomGreater(i, n);
        }
    }

    return a;
}

struct Spec {
    int n, ans;
};

Spec spec[21] = {
    {0, 0},
    {5, 2}, {8, 3}, {8, 0}, {8, 4},
    {50, 5}, {50, 15}, {50, 25}, {50, 10},
    {100, 20}, {100, 45}, {100, 30}, {100, 10}, {100, 50}, {100, 35},
    {800, 50}, {800, 150}, {800, 250}, {800, 350}, {800, 400}, {800, 100}
};

void writeCase(int id, const vector<int>& a, int ans) {
    int n = (int)a.size() - 1;

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

    fout << ans << '\n';
}

int main() {
    random_device rd;
    auto seed = rd() ^ chrono::steady_clock::now().time_since_epoch().count();
    rng.seed(seed);

    for (int id = 1; id <= 20; ++id) {
        int n = spec[id].n;
        int target = spec[id].ans;

        vector<int> a;

        // 理论上第一次就能成功；重试只是保险
        for (int tries = 0; tries < 100; ++tries) {
            a = generateArray(n, target);

            if (!a.empty() && solve(a) == target) {
                break;
            }
        }

        int answer = solve(a);
        writeCase(id, a, answer);

        cerr << "mutsumi_" << id
             << "  n=" << n
             << "  target=" << target
             << "  ans=" << answer << '\n';
    }

    return 0;
}