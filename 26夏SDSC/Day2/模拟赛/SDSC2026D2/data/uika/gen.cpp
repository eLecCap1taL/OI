#include <bits/stdc++.h>
using namespace std;

struct Test {
    int n, k, m;
    vector<int> b;
};

mt19937 rng(712367);

int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// 题解判定函数，同时用于生成 .ans
bool can(const Test &t) {
    if ((t.n - t.m) % (t.k - 1) != 0) return false;

    int h = (t.k - 1) / 2;

    for (int i = 0; i < t.m; ++i) {
        int left = t.b[i] - (i + 1);
        int right = (t.n - t.m) + (i + 1) - t.b[i];

        if (left >= h && right >= h) return true;
    }

    return false;
}

// 从 [L, R] 中随机选 cnt 个数，返回升序数组
vector<int> randomValuesFromRange(int L, int R, int cnt) {
    vector<int> res;
    int len = R - L + 1;

    if (cnt <= 0 || len <= 0) return res;

    if (cnt == len) {
        res.resize(len);
        iota(res.begin(), res.end(), L);
        return res;
    }

    // cnt 较小，用哈希集合避免 O(len) 构造
    if (cnt * 2 < len) {
        unordered_set<int> s;
        while ((int)s.size() < cnt) {
            s.insert(rnd(L, R));
        }
        res.assign(s.begin(), s.end());
        sort(res.begin(), res.end());
        return res;
    }

    vector<int> v(len);
    iota(v.begin(), v.end(), L);

    for (int i = 0; i < cnt; ++i) {
        int j = rnd(i, len - 1);
        swap(v[i], v[j]);
    }

    res.assign(v.begin(), v.begin() + cnt);
    sort(res.begin(), res.end());
    return res;
}

// 生成一个答案是 YES 的测试
Test genYESGivenN(int n, int fixedK, int maxQ) {
    while (true) {
        int k = fixedK ? fixedK : 2 * rnd(1, (n - 1) / 2) + 1;
        int h = (k - 1) / 2;

        int maxPossibleQ = (n - 1) / (k - 1);
        int qhi = min(maxPossibleQ, maxQ);

        if (qhi < 1) continue;

        int q = rnd(1, qhi);
        int m = n - q * (k - 1);

        int xlo = h + 1;
        int xhi = n - h;

        if (xlo > xhi) continue;

        int x = rnd(xlo, xhi);

        int lowerA = max(0, (m - 1) - (n - x - h));
        int upperA = min(m - 1, x - 1 - h);

        if (lowerA > upperA) continue;

        int a = rnd(lowerA, upperA);
        int c = m - 1 - a;

        vector<int> left = randomValuesFromRange(1, x - 1, a);
        vector<int> right = randomValuesFromRange(x + 1, n, c);

        vector<int> b = left;
        b.push_back(x);
        b.insert(b.end(), right.begin(), right.end());

        sort(b.begin(), b.end());

        Test t{n, k, m, b};

        if (can(t)) return t;
    }
}

// 生成一个答案是 NO 的测试
Test genNO(int n, int fixedK) {
    while (true) {
        int k = fixedK ? fixedK : 2 * rnd(1, (n - 1) / 2) + 1;
        int m = rnd(1, n - 1);

        // 情况 1：不满足整除条件，必为 NO
        if ((n - m) % (k - 1) != 0) {
            vector<int> b = randomValuesFromRange(1, n, m);
            Test t{n, k, m, b};

            if (!can(t)) return t;
        } else {
            // 情况 2：满足整除条件，但让 b 全部集中在左侧或右侧
            vector<int> b(m);

            if (rnd(0, 1) == 0) {
                iota(b.begin(), b.end(), 1);
            } else {
                int start = n - m + 1;
                iota(b.begin(), b.end(), start);
            }

            Test t{n, k, m, b};

            if (!can(t)) return t;
        }
    }
}

// 分配每个测试点的 n，保证有大有小，总和不超过 maxTotalN
vector<int> allocateN(int T, int maxN, int maxTotalN) {
    vector<int> n(T);

    int remain = maxTotalN;

    for (int i = 0; i < T; ++i) {
        int left = T - i;

        int maxC = min(maxN, remain - (left - 1) * 3);

        if (maxC < 3) maxC = 3;

        int cur = rnd(3, maxC);
        n[i] = cur;
        remain -= cur;
    }

    shuffle(n.begin(), n.end(), rng);

    return n;
}

struct FileConfig {
    int maxN;
    int fixedK;      // 0 表示不固定
    int maxQForYES;  // 对 YES 的测试，限制操作次数
};

FileConfig getConfig(int id) {
    if (id <= 5) {
        // n <= 6, k = 3
        return {6, 3, INT_MAX};
    }

    if (id <= 10) {
        // 若答案为 YES，则最多两次操作
        // n 上限可以自行调整，这里给 100000
        return {100000, 0, 2};
    }

    if (id <= 14) {
        // n <= 500
        return {500, 0, INT_MAX};
    }

    if (id <= 16) {
        // n <= 2000
        return {2000, 0, INT_MAX};
    }

    // n <= 2000000
    return {2000000, 0, INT_MAX};
}

void writeFile(int id, const vector<Test> &tests) {
    string inFile = "uika_" + to_string(id) + ".in";
    string ansFile = "uika_" + to_string(id) + ".ans";

    ofstream fin(inFile);
    ofstream fout(ansFile);

    fin << tests.size() << '\n';

    for (const Test &t : tests) {
        fin << t.n << ' ' << t.k << ' ' << t.m << '\n';

        for (int i = 0; i < t.m; ++i) {
            if (i) fin << ' ';
            fin << t.b[i];
        }

        fin << '\n';
        fout << (can(t) ? "YES" : "NO") << '\n';
    }
}

void generateFile(int id, int maxTotalN) {
    FileConfig cfg = getConfig(id);

    // 多测数量 2 ~ 50，且保证至少能放下
    int maxT = min(50, maxTotalN / 6);
    if (maxT < 2) maxT = 2;

    int T = rnd(2, maxT);
    T=maxT;

    vector<int> n = allocateN(T, cfg.maxN, maxTotalN);

    // 生成混合的 YES / NO 类型
    vector<int> types(T);

    for (int i = 0; i < T; ++i) {
        types[i] = (i < T / 2 ? 1 : 0); // 1 = YES, 0 = NO
    }

    shuffle(types.begin(), types.end(), rng);

    vector<Test> tests;
    tests.reserve(T);

    for (int i = 0; i < T; ++i) {
        if (types[i]) {
            tests.push_back(genYESGivenN(n[i], cfg.fixedK, cfg.maxQForYES));
        } else {
            tests.push_back(genNO(n[i], cfg.fixedK));
        }
    }

    writeFile(id, tests);

    cerr << "generated uika_" << id
         << " with " << T << " tests"
         << ", sum_n = " << accumulate(n.begin(), n.end(), 0)
         << '\n';
}

int main(int argc, char **argv) {
    int fileCnt = argc > 1 ? atoi(argv[1]) : 20;
    int maxTotalN = argc > 2 ? atoi(argv[2]) : 2000000;
    int seed = argc > 3 ? atoi(argv[3]) : 712367;

    rng.seed(seed);

    for (int id = 1; id <= fileCnt; ++id) {
        generateFile(id, maxTotalN);
    }

    return 0;
}