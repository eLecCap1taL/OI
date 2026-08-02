#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#define ll long long
using namespace std;
const int N=15;
const int M=2e3+5;
const ll mod=998244353;
ll n,a[N];
ll k[M][M];
ll qpow(ll x,ll k){
	ll ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod,k/=2;
	}
	return ret;
}
ll solve(){
	k[1][1]=1;
	k[2][1]=1,k[2][2]=1;
//	k[3][1]=3,k[3][2]=2,k[3][3]=3;
	for(int i=3;i<=n;i++){
		k[i][1]=(k[i-1][1]*(i-2)*2+k[i-1][1])%mod;
		for(int j=2;j<=i;j++){
			k[i][j]=(k[i-1][j-1]*(j-2)*2+k[i-1][j-1])%mod;
			ll rest=i-1-(j-2)-1;
			if(rest==0) continue;
			k[i][j]=(k[i][j]+(rest-1)*k[i-1][j]*2+k[i-1][j])%mod;
		}
	}
}
int main() {
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);  
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll fz=1,fm=1,prt=1;
	if(n==1)	  fz=a[1],fm=1;
	else if(n==2) fz=a[1]+a[2],fm=2;
	else if(n==3) fz=a[1]*3+a[3]*3+a[2]*2,fm=8;
	else {
		solve();
		for(int i=1;i<=n;i++)
			fz=(fz+k[n][i]*a[i])%mod;
		fm=qpow(2,n-1);
	}

	prt=prt*fz%mod;
	prt=prt*qpow(fm,mod-2)%mod;
	cout<<prt<<endl;
	return 0;
}
