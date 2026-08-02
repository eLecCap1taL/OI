//long term vegetable food
#include<bits/stdc++.h>
#define int long long
#define N 300010
#define P 998244353
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n;
struct edge{
	int v,w;
};
vector<edge>e[N],g[N];
void dfs1(int u,int fa){
	for(edge ed:e[u]){
		int v=ed.v;
		if(v==fa)continue;
		g[u].push_back(ed);
		dfs1(v,u);
	}
}
int f[N][2];
void dfs2(int u,int wu){
	int len=g[u].size();
	if(!len){
		f[u][0]=f[u][1]=1;
		return;
	}
	vector<pii>dp(len);
	for(int i=len-1;i>=0;i--)dfs2(g[u][i].v,g[u][i].w);
	//up part
	if(g[u][len-1].w>wu){
		dp[len-1].fi=f[g[u][len-1].v][0]%P;
		dp[len-1].se=f[g[u][len-1].v][1]%P;
	}else{
		dp[len-1].fi=0;
		dp[len-1].se=f[g[u][len-1].v][1]%P;
	}
	for(int i=len-2;i>=0;i--){
		int v=g[u][i].v,w=g[u][i].w;
		if(w>wu){
			dp[i].fi=f[v][0]*dp[i+1].fi%P;
			dp[i].se=(dp[i+1].fi+dp[i+1].se)%P*f[v][1]%P;
		}else{
			dp[i].fi=0;
			dp[i].se=(dp[i+1].fi+dp[i+1].se)%P*f[v][1]%P;
		}
	}
	f[u][0]=(dp[0].fi+dp[0].se)%P;
	//down part
	for(int i=0;i<len;i++)dp[i].fi=dp[i].se=0;
	if(g[u][len-1].w>wu){
		dp[len-1].fi=f[g[u][len-1].v][0]%P;
		dp[len-1].se=0;
	}else{
		dp[len-1].fi=f[g[u][len-1].v][0]%P;
		dp[len-1].se=f[g[u][len-1].v][1]%P;
	}
	for(int i=len-2;i>=0;i--){
		int v=g[u][i].v,w=g[u][i].w;
		if(w>wu){
			dp[i].fi=f[v][0]*dp[i+1].fi%P;
			dp[i].se=0; 
		}else{
			dp[i].fi=f[v][0]*dp[i+1].fi%P;
			dp[i].se=(dp[i+1].fi+dp[i+1].se)%P*f[v][1]%P;
		}
	}
	f[u][1]=(dp[0].fi+dp[0].se)%P;
}
signed main(){
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%lld%lld",&u,&v);
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	dfs1(1,0);
	for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end(),[](edge x,edge y){return x.w<y.w;});
	dfs2(1,0);//can be 0 or inf, 0 output f[1][0]
	printf("%lld",f[1][0]%P);
	return 0;
}
