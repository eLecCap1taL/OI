#include <bits/stdc++.h>

using namespace std;

const int N = 1, mod = 1145141;

long long f[mod + 10], inv[mod + 10];

int ksm(long long x, int k){
	long long res = 1;
	for (;k;k >>= 1, x = x * x % mod)
		if (k & 1) res = res * x % mod;
	return res;
}

void init(){
	f[0] = 1;
	for (int i = 1;i < mod;i ++)
		f[i] = 1ll * f[i - 1] * i % mod;
	
	inv[mod - 1] = ksm(f[mod - 1], mod - 2);
	for (int i = mod - 2;i > 0;i --)
		inv[i] = inv[i + 1] * (i + 1) % mod;
	
}

void work(){
	int d, n, a;
	scanf ("%d%d%d", &d, &n, &a);
	if (n >= mod){
		puts("0");
		return;
	}
	if (d == 1){
		cout << f[n + a - 1] * inv[a - 1] << endl;
		return;
	}
	if (d % mod == 0){
		cout << ksm(a, n) << endl;
		return;
	}
	if ((1ll * n * d % mod + a) % d == 0ll){
		puts("0");
		return;
	}
	long long now = a, ans = 1;
	for (int i = 0;i < n;i ++){
		ans = (ans * now) % mod;
		now = (now + d) % mod;
	}
	cout << ans << endl;
}

int main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	
	init();
	int t;
	scanf ("%d", &t);
	while (t --) work(); 
	
	
	return 0;
} 
