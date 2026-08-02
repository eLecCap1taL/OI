#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+10,mod=998244353;
ll n,dp[N][2];
vector<pair<ll,ll> >e[N];
int main(){
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	cin>>n;
	for(ll i=1,u,v,w;i<n;i++){
		cin>>u>>v;
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	if(e[n].size()==n-1){
		cout<<n;
		return 0; 
	}
	dp[1][1]=dp[1][0]=1;
	for(ll i=2;i<=n;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
		dp[i][1]=dp[i-1][0]%mod;
	}
	cout<<(dp[n-1][1]+dp[n-1][0])%mod;
	return 0;
}
