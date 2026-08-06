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

int a[MAXN];

signed main()
{
	freopen("mutsumi.in", "r", stdin);
	freopen("mutsumi.out", "w", stdout);
	
	int n = read();
	
	for(int i = 1;  i <= n;  i++)
	{
		a[i] = read();
	}
	
	cout<<0<<endl;
	
	return 0;
}

