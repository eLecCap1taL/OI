#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10,N1=5010;
const ll mod=998244353;
ll qpow(ll x,ll y){
	ll sum=1;
	while(y){
		if(y&1)sum=sum*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return sum;
}
int n,a[N];
ll E[N1][N1],inv[N],sum[N1][N1][2];
int main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	ll inv2=qpow(2ll,mod-2);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==1){
		printf("%d",a[1]);
		return 0;
	}
	if(n==2){
		printf("%d",1ll*(a[1]+a[2])*inv2%mod);
		return 0;
	}
	for(int i=1;i<=n;i++)inv[i]=qpow(1ll*i,mod-2);
	for(int i=1;i<=n;i++)E[i][i]=sum[i][i][0]=sum[i][i][1]=a[i];
	for(int len=2;len<=n;len++){
		for(int l=1;l<=n;l++){
			int r=l+len-1;
			E[l][r]=(sum[l][r-1][0]+sum[l+1][r][1])*inv2%mod;
			E[l][r]=E[l][r]*inv[len-1]%mod;
			sum[l][r][0]=(sum[l][r-1][0]+E[l][r])%mod;
			sum[l][r][1]=(sum[l+1][r][1]+E[l][r])%mod;
		}
	}
	printf("%lld",E[1][n]);
	return 0;
}

