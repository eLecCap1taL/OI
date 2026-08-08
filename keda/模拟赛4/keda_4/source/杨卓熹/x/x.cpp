#include<iostream>
#include<cmath>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 998244353
using namespace std;
const int maxn=1000005;
ll t,m,n,a[maxn];
ll nxt[maxn];
inline void init()
{
	for(int i=1;i<=n;i++) nxt[i]=0;
}
inline ll powder(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=(ans%mod*a%mod)%mod;
		a=(a%mod*a%mod);
		b>>=1;
	}
	return ans;
}
inline void fre()
{
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		init();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			ll j=nxt[i-1];
			while(j&&a[i]!=a[j+1]) j=nxt[j];
			if(a[i]==a[j+1]) j++;
			nxt[i]=j;
		}
		ll x=n,ans=0;
		while(x)
		{
			ans=powder(m,x)%mod;
			x=nxt[x];
		}
		cout<<ans%mod<<endl;
	}
	return 0;
} 
