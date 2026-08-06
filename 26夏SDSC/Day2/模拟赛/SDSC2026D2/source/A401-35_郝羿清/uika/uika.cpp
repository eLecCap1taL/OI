#include <bits/stdc++.h>
using namespace std;

bool ST;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
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

const int MAXN = 2e6 + 5;
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
int t;
int n, k, m;
int a[MAXN], b[MAXN];

void solve() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n;i++) {
        a[i] = i;
    }
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
    }
    cout << "YES";
}

bool ED;

int main() {
    freopen("uika.in", "r", stdin);
    freopen("uika.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    // TODO: 键入代码
    int n = read();
    while (n--) solve();

    cerr << "Time: " << (double)clock() / CLOCKS_PER_SEC << " s\n";
    cerr << "Memory: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB\n";
    return 0;
}
/*
1 2 3 4 5 6 7

*/