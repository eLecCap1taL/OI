#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
bool st;
const ll N=9e6+5,mod=1145141,INF=0x3f3f3f3f3f3f3f3f;
ll n,m,k,ans,T;
ll d,a;
ll power(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod; 
	return ans;
}
ll A[N];
namespace sub1{
	void sovle(){
		a%=mod;
		ll sum=A[a+n-1];
		if(a) sum*=power(A[a-1],mod-2);
		cout<<sum%mod<<endl;
		return ;
	}
}
bool ed;
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
//	cerr<<((&st)-(&ed))/1024.0/1024;
	freopen("sakiko.in","r",stdin);
//	freopen("rand.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	A[0]=1;
	for(ll i=1;i<=5*mod;i++) A[i]=A[i-1]*i%mod;
	cin>>T;
	while(T--){
		cin>>d>>n>>a;
		if(d%mod==0){cout<<power(a,n)<<endl;continue;}
		if(n>2e6){
			cout<<0<<endl;continue;
		}
		a%=mod,d%=mod;
		a*=power(d,mod-2);a%=mod;
		
//		if(d==1){sub1::sovle();continue;}
		ans=a;
		ans*=A[a+n-1]*power(A[a],mod-2)%mod;
		ans%=mod;
		ans*=power(d,n);
		ans%=mod;
		cout<<ans<<endl;
//		a%=mod,d%=mod;
//		for(ll i=0;i<n;i++){
//			ans*=(a+(i%mod)*d)%mod,ans%=mod;
////			if((a+(i%mod)*d)%mod==0){
////				cout<<"! "<<a<<" "<<i<<" "<<d<<endl;
////			}
//		} 
//		cout<<ans<<endl;
		
	}
	return 0;
}
/*
380192
0
0
0
0
0
675712
511553
0
0
*/
