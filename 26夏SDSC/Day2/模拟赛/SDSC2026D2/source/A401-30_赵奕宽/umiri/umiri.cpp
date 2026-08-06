#include<bits/stdc++.h>
using namespace std;
typedef long long L;
map<int, pair<int, L>> s;
int n, m;

auto sp(int x) {
    if (x > n)return s.end();
    auto i = s.upper_bound(x);
    --i;
    int a = i->first, b = i->second.first;
    L c = i->second.second;
    if (a == x)return i;
    i->second.first = x - 1;
    return s.insert({x, {b, c}}).first;
}

int main() {
	freopen("umiri.in", "r", stdin);
	freopen("umiri.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    s[1] = {n, 0};
    while (m --) {
        int a;
        L b;
        cin >> a >> b;
        auto i = sp(a + 1);
        -- i;
        while (b > 0) {
            int f = i -> first;
            L v = i -> second.second;
            int c = a - f + 1;
            auto p = i;
            L u = -1;
            if (p != s.begin()) {
                --p;
                u = p -> second.second;
            }
            if (u == -1 || u > v + 1) {
                L x = (u == -1) ? (1LL << 60) : (u - v - 1);
                L y = b / c;
                if (y > x) y = x;
                if (y > 0) {
                    i -> second.second += y;
                    b -= y * c;
                    continue;
                }
            }
            if (b >= c) {
                i -> second.second ++;
                b -= c;
                if (u == i -> second.second){
                    p->second.first = a;
                    i = s.erase(i);
                    i = p;
                }
            }
            else {
                int g = f + b;
                L w = v + 1;
                i = s.erase(i);
                s[g] = {a, v};
                if (u == w) {
                    p->second.first = g - 1;
                }
                else {
                    s[f] = {g - 1, w};
                }
                b = 0;
            }
        }
    }
    for (auto & e : s) {
        int a = e.first, b = e.second.first;
        L c = e.second.second;
        for (int d = a; d <= b; d ++) {
			cout << c << '\n';
		}
    }
    return 0;
}
