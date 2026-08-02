#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define ft first
#define sd second
using namespace std;
const ll N=3e5+5,mod=998244353;
mt19937_64 rd(time(0));
ll n,f[N][2];
vector<pair<ll,ll>>e[N];
ll inv(ll x){
	ll b=mod-2,hui=1;
	for(;b;b>>=1,x=x*x%mod)if(b&1)hui=hui*x%mod;
	return hui;
}
void dfs(ll x,ll fa,ll W){
	f[x][1]=f[x][0]=1;
	sort(e[x].begin(),e[x].end());
	ll xi[e[x].size()+2],da[e[x].size()+2],tot=0,totda=0;
	ll ans=0,now=1,now2=1;
	for(int i=0;i<e[x].size();i++){
		ll v=e[x][i].sd,w=e[x][i].ft;
		if(v==fa)continue;
		dfs(v,x,w);
		if(w<W){
			f[x][1]*=f[v][0];f[x][1]%=mod;
			xi[++tot]=v;now2*=f[v][1];now2%=mod;
		}
		else {
			f[x][0]*=f[v][1];f[x][0]%=mod;
			da[++totda]=v;now*=f[v][1];now%=mod;
		}
	}
	if(x==1)return;
	ans=now;
	for(int i=1;i<=totda;i++){
		ll v=da[i];
		now*=inv(f[v][1])*f[v][0]%mod;now%=mod;
		ans+=now;ans%=mod;
	}
	f[x][1]*=ans;f[x][1]%=mod;
	ans=now2;
	for(int i=1;i<=tot;i++){
		ll v=xi[i];
		now2*=inv(f[v][1])*f[v][0]%mod;now2%=mod;
		ans+=now2;ans%=mod;
	}
	f[x][0]*=ans;f[x][0]%=mod;
	//cout<<x<<' '<<f[x][0]<<' '<<f[x][1]<<endl;
}
int main(){
 	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		e[u].pb(mp(i,v));e[v].pb(mp(i,u));
	}
	dfs(1,0,0);ll tot=0,now=1,ans=0,da[N];
	for(int i=0;i<e[1].size();i++)da[++tot]=e[1][i].sd,now*=f[e[1][i].sd][1],now%=mod;
	ans=now;
//	cout<<now<<endl;
	for(int i=1;i<=tot;i++){
		ll v=da[i];
		now*=inv(f[v][1])*f[v][0]%mod;now%=mod;
		ans+=now;ans%=mod;
	}
	cout<<ans;
    return 0;
}
/*
15
9 10 
15 10 
10 7 
9 3 
12 5 
1 9 
13 9 
9 5 
11 2 
6 4 
2 9 
10 8 
8 14 
12 6 

*/
