#include <iostream>
using namespace std;
const int MD = 1145141;
using ll = long long;
ll jc[MD], ny[MD];
inline ll fast(ll n, ll p) {
    ll ans = 1;
    while (p > 0) {
        if (p & 1) ans = ans * n % MD;
        n = n * n % MD, p >>= 1;
    }
    return ans;
}
int main() {
    freopen("sakiko.in", "r", stdin);
    freopen("sakiko.out", "w", stdout);
    jc[0] = 1;
    for (int i = 1; i < MD; i++) jc[i] = jc[i - 1] * i % MD;
    ny[MD - 1] = fast(jc[MD - 1], MD - 2);
    for (int i = MD - 2; i >= 0; i--) ny[i] = ny[i + 1] * (i + 1) % MD;
    int ttt;
    cin >> ttt;
    while (ttt--) {
        ll d, n, a;
        cin >> d >> n >> a;
        if (d % MD == 0) {
            cout << n * a % MD << endl;
            continue;
        }
        int pos = fast(d, MD - 2) * a % MD;
        // cout << pos << endl;
        if (n + pos - 1 >= MD) cout << 0 << endl;
        else cout << fast(d, n) * jc[n + pos - 1] % MD * ny[pos - 1] % MD << endl;
    }
}