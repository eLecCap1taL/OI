#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1145141;
ll f[p], g[p];
ll pow(ll a, ll b) {
	ll r = 1;
	 a %= p;
	 for (; b; b >>= 1, a = a * a % p) {
		if (b & 1) {
			r = r * a % p;
		}
	 }
	 return r;
}

int main() {
	freopen("sakiko.in", "r", stdin);
	freopen("sakiko.out", "w", stdout); 
	f[0] = 1;
	int i;
	for (i = 1; i < p; i ++) {
		f[i] = f[i - 1] * i % p;
	}
	g[p - 1] = pow(f[p - 1], p - 2);
	for (i = p - 1; i >= 1; i --) {
		g[i - 1] = g[i] * i % p;
	}
	/*
	for (int i = 1; i <= 20; i ++) {
		cout << f[i] << " ";
	} 
	cout << "\n";
	for (int i = 1; i <= 20; i ++) {
		cout << g[i] << " ";
	}
	*/
	int t;
	scanf("%d", &t);
	while (t --) {
		ll d, n, a;
		scanf("%lld %lld %lld", &d, &n, &a);
		d %= p, a %= p;
		if (d == 0) {
			if (a == 0) {
				printf("0\n");
			}
			else {
				printf("%lld\n", pow(a, n));
			}
		}
		else {
			ll x = a * pow(d, p - 2) % p;
			if (x == 0 || n > p - x) {
				printf("0\n");
			}
			else {
				ll s = pow(d, n) * f[x + n - 1] % p * g[x - 1] % p;
				printf("%lld\n", s);
				//printf("%lld\n%lld\n%lld\n", pow(d, n), f[x + n - 1], g[x - 1]);
			}
		}
	}
	return 0;
}
