#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=1e6+5;
int n,a[N];
int M;
int qpow(int x,int y){
	int res=1ll%mod;
	while(y>0){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int cl(int x,int y){
	if((x+y)%2==0){
		return (x+y)/2ll%mod;
	}
	else{
		return (x+y)*M;
	}
}
signed main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	M=qpow(2,mod-2);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1) return cout<<(a[1]%2==0?a[1]%mod:a[1]*M),0;
	if(n==2) return cout<<cl(a[1],a[2]),0;
	if(n==3){
		int res=cl(cl(cl(a[1],a[2]),a[3]),cl(cl(a[2],a[3]),a[1]));
		return cout<<res,0;
	}
	return 0;
}
