#include <bits/stdc++.h>

using namespace std;

#define LL long long

const int mod = 998244353;
const int N = 2010;

LL ksm(LL x, int k){
	LL res = 1;
	for (;k;k >>= 1, x = x * x % mod)
		if (k&1) res = res * x % mod;
	return res;
}
int n;
LL f[N][N];
void init(){
	f[1][1] = 1;
	for (int i = 2;i <= n;i ++)
		for (int j = 1;j <= i;j ++){
			if (j < i) f[i][j] += f[i - 1][j] * (2 * (i - j) - 1) % mod * 499122177 % mod;
			if (j > 1) f[i][j] += f[i - 1][j - 1] * (2 * j - 3) % mod * 499122177 % mod;
		}
}

int main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	int t, a, b;
	scanf ("%d", &n);
	init();
	LL ans = 0;
	for (int i = 1, x;i <= n;i ++){
		scanf ("%d", &x);
		ans = (ans + f[n][i] * x) % mod;
	}
	for (int i = 2;i < n;i ++)
		ans = ans * ksm(i, mod - 2) % mod;
	cout << ans << endl;
	return 0;
} 
