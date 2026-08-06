#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;
using ll    = long long;
const int N = 1e5 + 10;
using pii   = pair<int, int>;
struct SegTree {
    ll tsum[N << 2], tag[N << 2], tmax[N << 2];
    inline void upd(int p, ll x, int l, int r) {
        tag[p]  = x;
        tsum[p] = x * (r - l + 1);
        tmax[p] = x;
    }
    inline void pushdown(int p, int l, int r) {
        if (tag[p] == 0) return;
        int mid = (l + r) >> 1;
        upd(p << 1, tag[p], l, mid);
        upd(p << 1 | 1, tag[p], mid + 1, r);
        tag[p] = 0;
    }
    inline void pushup(int p) {
        tsum[p] = tsum[p << 1] + tsum[p << 1 | 1];
        tmax[p] = max(tmax[p << 1], tmax[p << 1 | 1]);
    }
    inline void update(int p, int l, int r, int x, int y, ll v) {
        if (x <= l && r <= y) return upd(p, v, l, r);
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        if (x <= mid) update(p << 1, l, mid, x, y, v);
        if (y > mid) update(p << 1 | 1, mid + 1, r, x, y, v);
        pushup(p);
    }
    inline ll query_max(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tmax[p];
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        ll ans  = 0;
        if (x <= mid) ans = max(ans, query_max(p << 1, l, mid, x, y));
        if (y > mid) ans = max(ans, query_max(p << 1 | 1, mid + 1, r, x, y));
        return ans;
    }
    inline ll query_sum(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tsum[p];
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        ll ans  = 0;
        if (x <= mid) ans += query_sum(p << 1, l, mid, x, y);
        if (y > mid) ans += query_sum(p << 1 | 1, mid + 1, r, x, y);
        return ans;
    }
} tree;
int n;
struct ODT {
    set<pii> s;
    vector<int> pts;
    inline void init(int n) {
        s.insert({1, n});
        pts.push_back(1);
    }
    inline void split(int x) {
        auto it     = prev(s.upper_bound({x, 1e9}));
        auto [l, r] = *it;
        if (l < x) {
            s.erase(it);
            s.insert({l, x - 1});
            s.insert({x, r});
            pts.insert(lower_bound(pts.begin(), pts.end(), x), x);
        }
    }
    inline void cover(int l, int r) {
        split(l), split(r + 1);
        // for (auto [l, r] : s) fprintf(stderr, "(%d,%d) ", l, r);
        // cerr << endl;
        // for (auto x : pts) fprintf(stderr, "%d ", x);
        // cerr << endl;
        auto beg = s.lower_bound({l, 0});
        auto ed  = s.upper_bound({r, 1e9});
        vector<pii> er;
        for (auto it = beg; it != ed; it = next(it)) er.push_back(*it);
        for (auto x : er) s.erase(s.find(x));
        s.insert({l, r});
        pts.erase(upper_bound(pts.begin(), pts.end(), l), upper_bound(pts.begin(), pts.end(), r));
        while (l > 1 && tree.query_max(1, 1, n, l, l) == tree.query_max(1, 1, n, l - 1, l - 1)) {
            auto pi       = s.find({l, r});
            auto [pl, pr] = *prev(pi);
            s.erase(pi);
            s.erase(s.find({pl, pr}));
            pts.erase(lower_bound(pts.begin(), pts.end(), l));
            s.insert({l = pl, r});
        }
    }
} odt;
int main() {
    freopen("umiri.in", "r", stdin);
    freopen("umiri.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int m;
    cin >> n >> m;
    odt.init(n);
    while (m--) {
        // cerr << m << "\n";
        ll a, b;
        cin >> a >> b;
        int l = 0, r = odt.pts.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (odt.pts[mid] > a) {
                r = mid - 1;
                continue;
            }
            // cerr << l << " " << r << " " << mid << endl;
            ll tm  = tree.query_max(1, 1, n, odt.pts[mid], a);
            ll ts  = tree.query_sum(1, 1, n, odt.pts[mid], a);
            ll res = tm * (a - odt.pts[mid] + 1) - ts;
            if (res > b) l = mid + 1;
            else r = mid;
        }
        // cerr << r << endl;
        int lp  = odt.pts[r];
        int len = a - lp + 1;
        ll tm   = tree.query_max(1, 1, n, lp, a);
        ll ts   = tree.query_sum(1, 1, n, lp, a);
        ll res  = tm * len - ts;
        // cout << lp << " " << tm << " " << ts << " " << res << endl;
        res   = b - res;
        ll ac = res / len + tm;
        // cerr << lp << " " << a << " " << ac << " " << n << endl;
        tree.update(1, 1, n, lp, a, ac);
        if (res % len) {
            int add = res % len;
            tree.update(1, 1, n, lp, lp + add - 1, ac + 1);
            odt.cover(lp + add, a);
            odt.cover(lp, lp + add - 1);
        } else odt.cover(lp, a);
    }
    for (int i = 1; i <= n; i++) cout << tree.query_max(1, 1, n, i, i) << "\n";
}