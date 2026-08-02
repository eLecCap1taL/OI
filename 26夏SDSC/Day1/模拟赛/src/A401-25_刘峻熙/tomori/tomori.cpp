#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n;
long long inv;
long long ans;
long long a[15];
long long nxt[15];
long long fac[15];
long long ksm(long long a,long long b)
{
	long long res=1,now=a;
	while(b)
	{
		if(b&1) res=res*now%mod;
		now=now*now%mod;
		b>>=1;
	}
	return res;
}
void dfs(long long x)
{
	if(x==1)
	{
		ans=(ans+a[1])%mod;
		return;
	}
	long long now=1;
	while(nxt[now])
	{
		long long tnxt=nxt[now],ta=a[now];
		a[now]=(a[now]+a[nxt[now]])*inv%mod;
		nxt[now]=nxt[nxt[now]];
		dfs(x-1);
		nxt[now]=tnxt;
		a[now]=ta;
		now=nxt[now];
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	inv=ksm(2,mod-2);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	fac[0]=1;
	for(long long i=1;i<n;i++)
	{
		nxt[i]=i+1;
		fac[i]=fac[i-1]*i%mod;
	}
	dfs(n);
	cout<<ans*ksm(fac[n-1],mod-2)%mod;
	return 0;
}
