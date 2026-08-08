#include<iostream>
#include<cmath>
#include<map> 
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
using namespace std;
const int maxn=1000005;
ll t,n,m,a[maxn],h[maxn],sum=0,sum1=0;
map<ll,ll> mp[maxn];
inline ll powder(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=(ans%mod*a%mod)%mod;
		a=(a%mod*a%mod)%mod;
		b>>=1;
	}
	return ans%mod;
}
inline void init()
{
	sum=sum1=0;
	for(int i=0;i<=m-1;i++) mp[i].clear();
}
inline void fre()
{
	freopen("st.in","r",stdin);
	freopen("st.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>t;
	init(); 
	while(t--)
	{
		cin>>n>>m;
		init();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			ll x=rand();
			h[i]=x%mod;
			sum=(sum%mod+h[i]%mod)%mod;
		}
		sum=(sum%mod*powder(m,mod-2)%mod)%mod;
		mp[0][0]=1;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			sum1=(sum1%mod+h[a[i]]%mod)%mod;
			ll x=(sum1-i%mod*sum%mod+mod)%mod;
			ans+=mp[i%m][x];
			mp[i%m][x]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
