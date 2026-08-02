#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 502;
int a[N][N], cnt[N], ans[N][N];
int main() {
    freopen("anon.in", "r", stdin);
    freopen("anon.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for (int t = 1 - n; t <= n - 1; t++) {
        memset(cnt, 0, sizeof(cnt));
        int nl = 0, res = 0;
        for (int i = min(n + t, n); i > 0 && i - t > 0; i--) {
            int j = i - t;
            nl++;
            for (int k = 0; k < nl; k++) {
                int x = i + k, y = j;
                if (!cnt[a[x][y]]) res++;
                cnt[a[x][y]]++;
            }
            for (int k = 1; k < nl; k++) {
                int x = i, y = j + k;
                if (!cnt[a[x][y]]) res++;
                cnt[a[x][y]]++;
            }
            while (res > k) {
                for (int k = 0; k < nl; k++) {
                    int x = i + k, y = j + nl - 1;
                    cnt[a[x][y]]--;
                    if (!cnt[a[x][y]]) res--;
                }
                for (int k = 1; k < nl; k++) {
                    int x = i + nl - 1, y = j + k - 1;
                    cnt[a[x][y]]--;
                    if (!cnt[a[x][y]]) res--;
                }
                nl--;
            }
            ans[i][j] = nl;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
}