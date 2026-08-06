#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ft first
#define sd second
using namespace std;
const ll N=2e5+5,mod=1145141;
mt19937_64 rd(time(0));
ll T,jie[mod*2];
ll poww(ll a,ll b){
	ll hui=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)hui=hui*a%mod;
	return hui;
}
ll inv(ll x){
	return poww(x,mod-2);
}
int main(){
 	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>T;jie[0]=1;
	for(int i=1;i<mod*2;i++)jie[i]=jie[i-1]*i%mod;
	while(T--){
		ll d,a,n;
		cin>>d>>n>>a;
		if(d==0){
			ll b=n;
			cout<<poww(a,n)<<endl;
			continue;;
		}
		if(!a){
			cout<<0<<endl;continue;
		}
	//	ll x=-a*inv(d)%mod;x+=mod;x%=mod;
		if(n>=mod){
			cout<<0<<endl;
		}
		else{
			a=a*inv(d)%mod;
			ll ans=poww(d,n);
			ans*=inv(jie[a-1])*jie[a+n-1]%mod;
			ans%=mod;
			cout<<ans<<endl;
		}
	}
	
	
    return 0;
}

