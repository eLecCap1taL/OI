#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2005,mod=1145141;
ll t,d,n,a,ans;
ll qow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	cin>>t;
	while(t--){
		ans=1;
		cin>>d>>n>>a;
		if(d%mod==0){
			cout<<qow(a,n)<<"\n";
			continue;
		}
		for(ll i=0;i<n;i++){
			ans=ans*(a%mod+(i%mod*d%mod)%mod)%mod;
			if(ans==0)break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
