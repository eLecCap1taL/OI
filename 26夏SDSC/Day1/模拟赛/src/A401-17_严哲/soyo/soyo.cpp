#include<bits/stdc++.h>
#define mod 998244353
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
const int N=3e5+5;
int n,vis[N];
struct Edge{
	int head[N],idx,maxn;
	struct edge{
		int nxt,to,val;
	}e[N<<1];
	void add(int u,int v,int w){
		e[++idx]=(edge){head[u],v,w};
		head[u]=idx;
		maxn=max({maxn,u,v});
	}
	void clear(){
		for(int i=1;i<=maxn;i++) head[i]=0;
		for(int i=1;i<=idx;i++) e[i].nxt=e[i].to=e[i].val=0;
		maxn=idx=0;
	}
}G;
pair<int,pii> E[N];
namespace Subtask1{
	int f[N][2];
	void solve(){
		f[2][0]=f[2][1]=1;
		for(int i=3;i<=n;i++){
			f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
			f[i][1]=f[i-1][0];
		}
		cout<<(f[n][0]+f[n][1])%mod;
	}
};
namespace Subtask2{
	void solve(){
		cout<<2;
	}
};
int F=0;
void dfs(int u,int fa,int fw){
	for(int i=G.head[u];i;i=G.e[i].nxt){
		int v=G.e[i].to;
		if(v==fa) continue;
		if(fw!=-1&&fw<G.e[i].val) F=1;
		dfs(v,u,G.e[i].val);
	}
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	cin>>n;int flag1=0,flag2=0;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		E[i]=mkp(i,mkp(u,v));
		if(u>v) swap(u,v);
		if(!(u==i&&v==i+1)) flag1=1;
		if(!(u==i&&v==n)) flag2=1;
	}
	if(!flag1) {Subtask1::solve();return 0;}
	if(!flag2) {Subtask2::solve();return 0;}
	int ans=0;
	for(int S=0;S<(1<<(n-1));S++){
		G.clear();for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=0;i<n-1;i++){
			int u=E[i+1].second.first,v=E[i+1].second.second,w=E[i+1].first;
			if((S>>i)&1) G.add(u,v,w);
			else G.add(v,u,w);
		}F=0;
		for(int i=1;i<=n;i++){
			dfs(i,0,-1);
			if(F) break;
		}
		if(!F) ans++;
	}
	cout<<ans;
	return 0;
}
