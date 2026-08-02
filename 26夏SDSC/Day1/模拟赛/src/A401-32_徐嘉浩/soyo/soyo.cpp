#include <iostream>
#include <vector>
#include <algorithm>
#define pii std::pair<int, int>

using std::cin;
using std::cout;
const int N = 3e5 + 10;
const int mod = 998244353;

int f[N][2]; // 0->ио,1->об 
int mul[N];
std::vector<pii> e[N];

void dfs(int x, int fa, int val)
{
	for (auto nxt : e[x])
	{
		int to = nxt.first;
		if (to != fa)
		{
			int v = nxt.second;
			dfs(to, x, v);
		}
	}
	if (e[x].size() == 1 && x != 1)
	{
		f[x][0] = f[x][1] = 1;
		return;
	}
	// 0
	std::sort(e[x].begin(), e[x].end(), [&](const pii &a, const pii &b){return a.second < b.second;});
	int xi = 1;
	for (auto nxt : e[x])
	{
		int to = nxt.first;
		if (to != fa)
		{
			if (nxt.second < val)
				xi = 1ll * xi * f[to][1] % mod;
		}
	}
	mul[e[x].size()] = 1;
	for (int i = e[x].size() - 1; i >= 0; --i)
	{
		int to = e[x][i].first;
		if (to == fa || e[x][i].second < val)
			mul[i] = mul[i + 1];
		else
			mul[i] = 1ll * mul[i + 1] * f[to][0] % mod;
	}
	int nm = 1;
	f[x][0] = 1ll * xi * mul[0] % mod;
	for (int i = 0; i < e[x].size(); ++i)
	{
		int to = e[x][i].first;
		if (to == fa)
			continue;
		if (e[x][i].second < val)
			continue;
		nm = 1ll * nm * f[to][1] % mod;
		f[x][0] = (f[x][0] + 1ll * nm * mul[i + 1] % mod * xi % mod) % mod;
	}
	// 1
	std::sort(e[x].begin(), e[x].end(), [&](const pii &a, const pii &b){return a.second > b.second;});
	xi = 1;
	for (auto nxt : e[x])
	{
		int to = nxt.first;
		if (to != fa)
		{
			if (nxt.second > val)
				xi = 1ll * xi * f[to][0] % mod;
		}
	}
	mul[e[x].size()] = 1;
	for (int i = e[x].size() - 1; i >= 0; --i)
	{
		int to = e[x][i].first;
		if (to == fa || e[x][i].second > val)
			mul[i] = mul[i + 1];
		else
			mul[i] = 1ll * mul[i + 1] * f[to][1] % mod;
	}
	nm = 1;
	f[x][1] = 1ll * xi * mul[0] % mod;
	for (int i = 0; i < e[x].size(); ++i)
	{
		int to = e[x][i].first;
		if (to == fa)
			continue;
		if (e[x][i].second > val)
			continue;
		nm = 1ll * nm * f[to][0] % mod;
		f[x][1] = (f[x][1] + 1ll * nm * mul[i + 1] % mod * xi % mod) % mod;
	}
}

int main()
{
	freopen("soyo.in", "r", stdin);
	freopen("soyo.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		e[x].push_back({y, i});
		e[y].push_back({x, i});
	}
	dfs(1, 0, 1e9);
//	for (int i = 2; i <= n; ++i)
//	{
//		cout << f[i][0] << ' ' << f[i][1] << '\n';
//	}
	cout << f[1][1] << '\n';
	return 0;
}
/*
4
1 2
2 3
3 4

5
*/
