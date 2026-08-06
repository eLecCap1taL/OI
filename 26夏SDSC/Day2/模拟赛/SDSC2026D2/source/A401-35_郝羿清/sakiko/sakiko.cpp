#include <bits/stdc++.h>
using namespace std;

bool ST;

const int MAXN = 1e5 + 5;
const int MOD = 1145141;
inline long long read() {
    long long x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline long long gcd(long long a, long long b) {
    long long t;
    while (b) { t = a % b; a = b; b = t; }
    return a;
}
inline int lowbit(int x) {
    return x & -x;
}
inline long long fpow(int x, int y) {
    long long res = 1;
    while (y) {
        if (y & 1) res = (res * x) % MOD;
        y = y / 2;
        x = (x * x) % MOD;
    }
    return res;
}


struct BIT {
    int bit[MAXN];
    void add(int p, int v) {
        for (; p < MAXN; p += lowbit(p)) bit[p] += v;
    }
    int sum(int p) {
        int s = 0;
        for (; p > 0; p -= lowbit(p)) s += bit[p];
        return s;
    }
};
struct SegmentTree {
    int n;
    vector<long long> st, lz;
    SegmentTree(int _n) : n(_n), st(4 * _n), lz(4 * _n) {}
    void push_down(int p, int l, int r) {
        if (!lz[p]) return;
        int m = (l + r) >> 1;
        st[p << 1] += lz[p] * (m - l + 1);
        st[p << 1 | 1] += lz[p] * (r - m);
        lz[p << 1] += lz[p];
        lz[p << 1 | 1] += lz[p];
        lz[p] = 0;
    }
    void update(int p, int l, int r, int ql, int qr, long long v) {
        if (ql <= l && r <= qr) {
            st[p] += v * (r - l + 1);
            lz[p] += v;
            return;
        }
        int m = (l + r) >> 1;
        push_down(p, l, r);
        if (ql <= m) update(p << 1, l, m, ql, qr, v);
        if (qr > m) update(p << 1 | 1, m + 1, r, ql, qr, v);
        st[p] = st[p << 1] + st[p << 1 | 1];
    }
    long long query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return st[p];
        push_down(p, l, r);
        int m = (l + r) >> 1;
        long long res = 0;
        if (ql <= m) res += query(p << 1, l, m, ql, qr);
        if (qr > m) res += query(p << 1 | 1, m + 1, r, ql, qr);
        return res;
    }
};
long long d, n, a;
// long long f1[1145145], f2[1145145];

// void init() {
//     f1[0] = 1;
//     for (int i = 1; i < MOD; i++) {
//         f1[i] = (f1[i - 1] * i) % MOD;
//     }
//     f2[MOD - 1] = fpow(f1[MOD - 1], MOD - 2);
//     for (int i = MOD - 1; i > 0; i--) {
//         f2[i - 1] = (f2[i] * i) % MOD;
//     }
// }
void solve() {
    d = read() % MOD, n = read(), a = read() % MOD;
    // long long t = (a * fpow(d, MOD - 2)) % MOD;
    // if (d == 0) {
    //     if (a == 0) {
    //         cout << "0\n";
    //         return;
    //     }
    //     else {
    //         cout << fpow(a, n) % MOD << "\n";
    //         return;
    //     }
    // }
    // if (n > MOD - t) {
    //     cout << "0\n";
    //     return;
    // }
    // cout << ((fpow(d, n) * f1[(t + n - 1)]) % MOD * f2[t - 1]) % MOD << '\n';
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * ((a + d * i) % MOD) % MOD;
    }
    cout << ans << '\n';
}

bool ED;

int main() {
    freopen("sakiko.in", "r", stdin);
    freopen("sakiko.out", "w", stdout);

    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    // TODO: 键入代码
    // init();
    int t = read();
    while (t--) solve();

    cerr << "Time: " << (double)clock() / CLOCKS_PER_SEC << " s\n";
    cerr << "Memory: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB\n";
    return 0;
}
