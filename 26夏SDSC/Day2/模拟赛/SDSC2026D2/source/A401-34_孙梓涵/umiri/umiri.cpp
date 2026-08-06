#include <bits/stdc++.h>
#define PII pair<int, int>
#define int long long
#define fi first
#define se second
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
const int MAXN = 1e5 + 7;
//const int MAXM = 1e5 + 7;

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

int p[MAXN];

signed main()
{
	freopen("umiri.in", "r", stdin);
	freopen("umiri.out", "w", stdout);
	int n = read(), m = read();
	
	for(int i = 1;  i <= m;  i++)
	{
		int a = read(), b = read();
		for(int t = 1;  t <= b;  t++)
		{
			int pos = 1;
			for(int j = 2;  j <= a;  j++)
			{
				if(p[j] < p[pos])
				{
					pos = j;
				}
			}
			p[pos]++;
		}
	}
	
	for(int i = 1;  i <= n;  i++)
	{
		cout<<p[i]<<endl;
	}
	
	return 0;
}
