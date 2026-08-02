#include <iostream>
using namespace std;
const int N = 11, MD = 998244353;
using ll = long long;
constexpr inline ll fast(ll n, ll p) {
    ll ans = 1;
    while (p > 0) {
        if (p & 1) ans = ans * n % MD;
        n = n * n % MD, p >>= 1;
    }
    return ans;
}
const ll _2 = fast(2, MD - 2);
ll f[N][N], a[N], jc[N];
int main() {
    freopen("tomori.in", "r", stdin);
    freopen("tomori.out", "w", stdout);
    jc[0] = 1;
    for (int i = 1; i < N; i++) jc[i] = jc[i - 1] * i % MD;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 0; i--) {
        f[i][i] = a[i];
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k < j; k++) {
                f[i][j] += (f[i][k] + f[k + 1][j]) * _2 % MD;
            }
            f[i][j] %= MD;
            f[i][j] = f[i][j] * fast(j - i, MD - 2) % MD;
        }
    }
    cout << f[1][n] << endl;
}