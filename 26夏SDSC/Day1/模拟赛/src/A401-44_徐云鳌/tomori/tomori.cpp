#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 300;

int a[maxn],n;
const int mod = 998244353;
int qpow(int a,int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int fa[maxn],sum[maxn];
int getf(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = getf(fa[x]);
}

void add(int &x,int y) 
{
	x += y;
	if(x >= mod) x -= mod;
}
void sol_bl()
{
	int all = 1,ans = 0;
	for(int i = 2;i <= n - 1;i++) all = all * i % mod;
	int iv = qpow(all,mod - 2),ivt = qpow(2,mod - 2);
	
	vector<int> vec;
	for(int i = 1;i < n;i++) vec.push_back(i);
	do {
	
		for(int i = 1;i <= n;i++) fa[i] = i,sum[i] = a[i];
		for(int x : vec)
		{
			int u = x,v = x + 1;
			u = getf(u),v = getf(v);
			fa[u] = v;
			sum[v] = (sum[v] + sum[u]) * ivt % mod;
		}
		int u = getf(1);
		add(ans,sum[u]);
	} while(next_permutation(vec.begin(),vec.end()));
	
	ans = ans * iv % mod;
	cout << ans << '\n';
	return ;
}

signed main()
{
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	if(n == 1) cout << (a[1] % mod) << '\n';
	else if(n == 2) cout << ((a[1] + a[2]) * qpow(2,mod - 2) % mod) << '\n'; 
	else if(n == 3)
	{
		int iv = qpow(2,mod - 2);
		int sa = ((a[1] + a[2]) * iv % mod + a[3]) * iv % mod * iv % mod;
		int sb = (a[1] + (a[2] + a[3]) * iv % mod) * iv % mod * iv % mod;
		cout << ((sa + sb) % mod) << '\n';
	}
	else sol_bl();
	return 0;
}
