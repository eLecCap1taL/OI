#include<bits/stdc++.h>
#define mod 1145141
#define int long long
#define mkp make_pair
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int ksm(int a,int b){
	int now=1;
	for(;b;b>>=1,a=a*a%mod){
		if(b&1) now=now*a%mod;
	}
	return now;
}
const int N=4e6+6;
int n,d,a,fac[N];
void Solve(){
	cin>>d>>n>>a;
	a%=mod;d%=mod;
	int pos=(mod-a)*ksm(d,mod-2)%mod;
	if(pos>=0&&pos<n){
		cout<<0<<'\n';
		return;
	}
	if(d==1){
		cout<<fac[a+n-1]*ksm(fac[a-1],mod-2)%mod<<'\n';
		return;
	}
	int ans=1;
	for(int i=0;i<n;i++){
		ans=ans*((a+i*d%mod)%mod)%mod;
	}
	cout<<ans<<'\n';
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	int T;cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}
