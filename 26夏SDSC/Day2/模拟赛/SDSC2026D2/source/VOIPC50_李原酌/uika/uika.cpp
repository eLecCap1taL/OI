#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int sum[N];
int main() {
    freopen("uika.in", "r", stdin);
    freopen("uika.out", "w", stdout);
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k, m;
        cin >> n >> k >> m;
        fill(sum + 1, sum + n + 1, 0);
        for (int i = 1; i <= m; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) sum[a[i]] = 1;
        for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
        vector<int> t;
        for (int i = 1; i <= n; i++) {
            if (i + k - 1 <= n && sum[i + k - 1] == sum[i - 1]) {
                i = i + k - 2;
                continue;
            }
            if (sum[i] == sum[i - 1]) t.push_back(i);
        }
        int cnt = t.size();
        if (cnt & 1) {
            cout << "NO\n";
            continue;
        }
        cnt >>= 1;
        if (cnt % ((k - 1) >> 1)) {
            cout << "NO\n";
            continue;
        }
        vector<int> pre, suf;
        for (int i = cnt; i >= 1; i--) pre.push_back(t[i - 1]);
        for (int i = cnt; i >= 1; i--) suf.push_back(t[i + cnt - 1]);
        for (int i = 1; i <= cnt / ((k - 1) >> 1); i++) {
            int tp, ts = suf.back();
            for (int i = 1; i <= cnt; i++) tp = pre.back(), pre.pop_back(), suf.pop_back();
            if (sum[ts - 1] == sum[tp]) {
                cout << "NO\n";
                goto No;
            }
        }
        cout << "YES\n";
        No:;
    }
}