#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
int n;
const int maxn = 3e5 + 20;
vector<int> G[maxn];

void add(int &x,int y)
{
	x += y;
	if(x >= mod) x -= mod;
}

int pre[maxn],lst[maxn];
// 考虑一段前缀都要是 0，后缀都要是 1 
int f[maxn][2];

void dfs(int u,int fa)
{
	f[u][0] = f[u][1] = 0;
	if(G[u].size() == 1 && u != 1) 
	{
		f[u][0] = f[u][1] = 1;
		return;
	}
	
	int rk = 0;
	for(int i = 0;i < (int)G[u].size();i++) 
	{
		int v = G[u][i];
		if(v == fa) 
		{
			rk = i + 1;
			continue;
		}
		dfs(v,u);
	}
	
	pre[0] = 1;
	for(int i = 0;i < (int)G[u].size();i++)
	{
		int v = G[u][i]; 
		pre[i + 1] = pre[i];
		if(v == fa) continue;
		pre[i + 1] *= f[v][0];
		pre[i + 1] %= mod;
	}
	lst[G[u].size() + 1] = 1;
	for(int i = (int)(G[u].size() - 1);i >= 0;i--) 
	{
		int v = G[u][i]; 
		lst[i + 1] = lst[i + 2];
		if(v == fa) continue;
		lst[i + 1] *= f[v][1];
		lst[i + 1] %= mod;
	}
	
	if(u == 1) rk = n + 1;
	
	for(int i = 0;i <= (int)G[u].size();i++)
	{
		if(i < rk) add(f[u][0],pre[i] * lst[i + 1] % mod);
		else add(f[u][1],pre[i] * lst[i + 1] % mod);
	}
}

signed main()
{
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i < n;i++) 
	{
		int u,v;cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	cout << f[1][0];
	return 0;
}
