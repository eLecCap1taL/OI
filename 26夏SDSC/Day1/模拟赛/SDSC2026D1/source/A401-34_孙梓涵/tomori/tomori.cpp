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
const int Mod = 998244353;
const int in2 = Mod / 2;

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
	freopen("tomori.in", "r", stdin);
	freopen("tomori.out", "w", stdout);
	int n = read();
	
	for(int i = 1;  i <= n;  i++)
	{
		a[i] = read();
	}
	
	if(n == 1)
	{
		cout<<a[1]<<endl;
	}
	else if(n == 2)
	{
		cout<<((a[1]+a[2]) * in2) % Mod<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	
	return 0;
}
