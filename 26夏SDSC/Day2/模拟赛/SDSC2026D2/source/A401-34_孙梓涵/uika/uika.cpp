#include <bits/stdc++.h>
#define PII pair<int, int>
#define int long long
#define fi first
#define se second
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
const int MAXN = 1e4 + 7;
const int MAXM = 1e5 + 7;

inline int read()
{
	int x = 0, w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0')
	{
		if(ch == '-')
		{
			w = -1;
		}
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * w;
}

int vis[100007];

signed main()
{
	freopen("uika.in", "r", stdin);
	freopen("uika.out", "w", stdout);
	
	int t = read();
	
	while(t--)
	{
		int n = read(), k = read(), m = read();
		int ans = 0;
		for(int i = 1;  i <= m;  i++)
		{
			int x = read();
			ans |= 1<<(x-1);
		}
		memset(vis, false, sizeof(vis));
		queue<int> q;
		int l = (1<<n) - 1;
		vis[l] = true;
		q.push(l);
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int i = 0;  i < n;  i++)
			{
				if(!(u >> i & 1))
				{
					continue; 
				}
				for(int j = i + 1;  j < n;  j++)
				{
					if(!(u >> j & 1))
					{
						continue;
					}
					for(int kk = j + 1;  kk < n;  kk++)
					{
						if(!(u >> kk & 1))
						{
							continue;
						}
						int zh = u & ~((1 << i) | (1 << kk));
						if(!vis[zh])
						{
							vis[zh] = true;
							q.push(zh);
						}
					}
				}
			}
		}
		if(vis[ans])
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return 0;
}
