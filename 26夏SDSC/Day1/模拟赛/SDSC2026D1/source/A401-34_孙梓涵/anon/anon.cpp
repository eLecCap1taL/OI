#include <bits/stdc++.h>
#define PII pair<int, int>
#define int long long
#define fi first
#define se second
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
const int MAXN = 500 + 7;
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

int a[MAXN][MAXN];

//int dp[MAXN][MAXN];//qian i hang qian j lie gong you duo shao ge bu yi yang de shu zi

int ans[MAXN][MAXN];

int cnt[MAXN];

int dp1[MAXN][MAXN], dp2[MAXN][MAXN];

signed main()
{
	freopen("anon.in", "r", stdin);
	freopen("anon.out", "w", stdout);
	
	int n = read(), k = read();
	
	int f = 1;
	
	for(int i = 1;  i <= n;  i++)
	{
		for(int j = 1;  j <= n;  j++)
		{
			a[i][j] = read();
			if(a[i][j] != 1 && a[i][j] != 2)
			{
				f = 0;
			}
		}
	}
	
	if(n <= 50)
	{
		for(int i = 1;  i <= n;  i++)
		{
			for(int j = 1;  j <= n;  j++)
			{
				memset(cnt, 0, sizeof(cnt));
				int maxx = min(n - j + 1LL, n - i + 1LL);
				int lenn = 0; // bu tong de ge shu ? nailong
				int cntt = 0; // zui chang de heng chang?
				for(int l = 1;  l <= maxx;  l++)
				{
//				
//				vector<int> cnt(n+1);
					int x1 = i + l - 1;
					for(int y1 = j;  y1 <= j + l - 1;  y1++)
					{
						if(++cnt[a[x1][y1]] == 1)
						{
							++cntt;
						}
//						cnt[col]++;
					}
					int y2 = j + l - 1;
					for(int x2 = i;  x2 <= i + l - 2;  x2++)
					{
//						int col = a[o][w];
						if(++cnt[a[x2][y2]] == 1)
						{
							++cntt;
						}
//						cnt[col]++;
					}
					if(cntt <= k)
					{
						lenn = l;
					}
					else
					{
						break;
					}
				}
				cout<<lenn<<' ';
			}
			cout<<endl;
		}
	}
	else if(f)
	{
		if(k >= 2)
		{
			for(int i = 1;  i <= n;  i++)
			{
				for(int j = 1;  j <= n;  j++)
				{
					cout<<min(n - i + 1LL, n - j + 1LL)<<' ';
				}
				cout<<endl;
			}
			return 0;
		}
		
		for(int i = n;  i >= 1;  i--)
		{
			for(int j = n;  j >= 1;  j--)
			{
				if(i == n || j == n)
				{
					dp1[i][j] = (a[i][j] == 1);
					dp2[i][j] = (a[i][j] == 2);
				}
				else
				{
					if(a[i][j] == 1)
					{
						dp2[i][j] = 0;
						dp1[i][j] = min(min(dp1[i+1][j], dp1[i][j+1]), dp1[i+1][j+1]) + 1;
					}
					if(a[i][j] == 2)
					{
						dp1[i][j] = 0;
						dp2[i][j] = min(min(dp2[i+1][j], dp2[i][j+1]), dp2[i+1][j+1]) + 2;
					}
				}
			}
		}
		
		for(int i = 1;  i <= n;  i++)
		{
			for(int j = 1;  j <= n;  j++)
			{
				cout<<max(dp1[i][j], dp2[i][j])<<' ';
			}
			cout<<endl;
		}
	}

	
//	for(int i = 1;  i <= n;  i++)
//	{
//		for(int j = 1;  j <= n;  j++)
//		{
//			cout<<ans[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	
	return 0;
}
