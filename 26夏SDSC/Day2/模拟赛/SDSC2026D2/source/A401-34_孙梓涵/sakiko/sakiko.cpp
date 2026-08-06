#include <bits/stdc++.h>
#define PII pair<int, int>
#define int long long
#define fi first
#define se second
#define ll long long
#define pb push_back
#define endl '\n'
using namespace std;
const int MAXN = 1145141 + 7;
const int MAXM = 1e5 + 7;
const int Mod = 1145141;

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

int fect[MAXN], inv[MAXN];

int Qmi(int base, int exp, int mod)
{
	int res = 1;
	base %= mod;
	while(exp > 0)
	{
		if(exp & 1)
		{
			res = res * base % mod;
		}
		base = base * base % mod;
		exp >>= 1;
	}
	return res%mod;
}

void init()
{
	fect[0] = 1;
	for(int i = 1;  i < Mod;  i++)
	{
		fect[i] = fect[i-1] * i % Mod;
	}
	inv[Mod-1] = Qmi(fect[Mod-1], Mod-2, Mod);
	for(int i = Mod-2;  i >= 0;  i--)
	{
		inv[i] = inv[i+1] * (i + 1) % Mod;
	}
}

signed main()
{
	freopen("sakiko.in", "r", stdin);
	freopen("sakiko.out", "w", stdout);
	init();
	int t = read();
	
//	for(int i = 1;  i <= 100;  i++)
//	{
//		cout<<fect[i]<<endl;
//	}
	
	while(t--)
	{
//		int d = read(), n = read(), a = read();
//		int ans = a;
//		while(--n)
//		{
//			a = (a+d) % Mod;
//			ans = (ans * a) % Mod;
//		}
//		cout<<ans%Mod<<endl;
		int d = read(), n = read(), a = read();
		
//		int ans = 0;
		int ad = (a % Mod + Mod) % Mod;
		int dd = (d % Mod + Mod) % Mod;
		
		if(dd == 0)
		{
			cout<<Qmi(ad, n, Mod)<<endl;
		}
		else
		{
			int invd = Qmi(dd, Mod-2, Mod);
			int x = ad * invd % Mod;
			if(x == 0)
			{
				cout<<0<<endl;
			}
			else if(n >= Mod)
			{
				cout<<0<<endl;
			}
			else
			{
				int pro;
				if(n > Mod - x)
				{
					pro = 0;
				}
				else
				{
					pro = fect[x+n-1]*inv[x-1]%Mod;
				}
				int powd=Qmi(dd, n, Mod);
				int ans = powd * pro % Mod;
				cout<<ans<<endl;
			}
		}
	}
	
	return 0;
}
//8:29 yixiexingzhia * (a+1) * (a+2) * ..... * (a+n-1) = jiecheng / jiecheng then d == 1 done wujie? think it   inv    kendingxuyaojiechengqusuanniyuan o womendiyiyanxiangchudeyinggaishid=1shidejiechengshikendingyouyongde danshi zenmbazheged==1pujidaon<=1e9shangnekaolv pai = a*(a+d)*(a+2d)*(a+3d)......(a+(n-1)*d)  = d^n*PAI(a*d^-1+k) womenchenggongbaniyuanpujidaolepubianqingkuangxiakezuo,danshi,ruheqiu kaolvQmi inv fect inv fect   不对啊  这个玩意好像无法在log/sqrt内计算啊  家了1 那么，这个玩意我们已经把Qmi和fect以及inv求出来了，总时间复杂度我认为是O（P+logn） 目前来看能过，考虑如何O（1）或者O（logn）或者O（sqrt）统计答案，，                                                    2
