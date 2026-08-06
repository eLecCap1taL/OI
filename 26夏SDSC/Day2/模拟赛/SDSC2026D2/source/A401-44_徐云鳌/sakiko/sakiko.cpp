#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1145141;
const int maxn = 3e6 + 10;
int n,d,a;
int fac[maxn],inv[maxn];

int qpow(int a,int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		a= a *a % mod;
		b >>= 1;
	}
	return res;
}

void init()
{
	fac[0] = 1;
	for(int i = 1;i <= 3000000;i++) 
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = qpow(fac[i],mod -2);
	}
}

void solve()
{
	cin >> d >> n >> a;
	int rr = 1;
	if(a == 0 || n >= mod) return cout << 0 << '\n',void();
	if(d == 0) return cout << qpow(a,n) << '\n',void();
//	cout << "fuck!\n";
	int r = n % mod;
	
	rr = qpow(d,r);
	
//	cout << rr << '\n';
	a = a * qpow(d,mod - 2) % mod;
	
//	cout << fac[a +r -1] <<" " << inv[a-1] << '\n';
//  cout << a-1 << '\n';
	rr = rr * fac[a + r - 1] % mod * inv[a - 1] % mod;
	cout << rr <<'\n';
	return ;
}

signed main()
{
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init();
	int t;cin >> t;
	while(t--) solve();
	return 0;
}

//为啥还有多测啊，原来暴力过不去的我草 
