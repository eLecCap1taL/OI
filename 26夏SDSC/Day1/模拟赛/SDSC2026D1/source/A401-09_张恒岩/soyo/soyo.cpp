#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+10;
const ll mod=998244353;
struct node{
	int to,w;
};
bool cmp(node x,node y){
	return x.w<y.w;
}
vector <node> e[N];
ll dp[N][2];
ll pre[N][2],suf[N][2];
int n,root,wfa[N];
ll ans=0;
void dfs(int u,int fa){
	int len=e[u].size();
	dp[u][0]=dp[u][1]=1;
	for(int i=0;i<len;i++){
		int v=e[u][i].to;
		if(v==fa)continue;
		wfa[v]=e[u][i].w;
		dfs(v,u);
	}
	if(u==root||len==1)return;
//	printf("%d %d %d\n",u,wfa[u],len);
	dp[u][0]=dp[u][1]=0;
	if(len==2){
		int son=e[u][0].to==fa?e[u][1].to:e[u][0].to;
		int w=e[u][0].to==fa?e[u][1].w:e[u][0].w;
		dp[u][0]+=dp[son][1];
		dp[u][1]+=dp[son][0];
		if(w<wfa[u])dp[u][1]+=dp[son][1];
		else dp[u][0]+=dp[son][0];
		dp[u][1]%=mod;
		dp[u][0]%=mod;
//		printf("	%d %d %d\n",u,dp[u][0],dp[u][1]);
		return;
	}
	ll mul[2];
	mul[0]=mul[1]=1;
	for(int i=0;i<len;i++){
		pre[i][0]=mul[0];
		pre[i][1]=mul[1];
		int v=e[u][i].to;
		if(v==fa)continue;
		mul[0]=mul[0]*dp[v][0]%mod;
		pre[i][0]=mul[0];	
		mul[1]=mul[1]*dp[v][1]%mod;
		pre[i][1]=mul[1];
	}
	mul[0]=mul[1]=1;
//	cout<<1;
	for(int i=len-1;i>=0;i--){
		suf[i][0]=mul[0];
		suf[i][1]=mul[1];
		int v=e[u][i].to;
		if(v==fa)continue;
		mul[0]=mul[0]*dp[v][0]%mod;
		suf[i][0]=mul[0];	
		mul[1]=mul[1]*dp[v][1]%mod;
		suf[i][1]=mul[1];
	}
//	if(maxn<=wfa[u]){
//		printf("0b %d %d\n",u,tmp);
	dp[u][0]=(dp[u][0]+pre[len-1][1])%mod;
//	}
//cout<<3;
	for(int i=0;i<len;i++){
		int v=e[u][i].to,w=e[u][i].w;
		if(v==fa)continue;
		if(w<=wfa[u])continue;
		ll tmp=1;
	//	cout<<2;
		if(i)tmp=tmp*pre[i-1][1]%mod;
		tmp=tmp*suf[i][0]%mod;
	//	cout<<i<<" ";
		dp[u][0]=(dp[u][0]+tmp)%mod;		
	}
//	if(minn>=wfa[u]){
	dp[u][1]=(dp[u][1]+pre[len-1][0])%mod;
//	}
	for(int i=0;i<len;i++){
		int v=e[u][i].to,w=e[u][i].w;
		if(v==fa)continue;
		if(w>=wfa[u])continue;
		ll tmp=1;
		tmp=tmp*pre[i][1]%mod;
		if(i!=len-1)tmp=tmp*suf[i+1][0];
	//	printf("1a %d %d %d\n",u,i,tmp);
		dp[u][1]=(dp[u][1]+tmp)%mod;
	}
//	printf("	%d %d %d\n",u,dp[u][0],dp[u][1]);
}
int main(){
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(node{v,i});
		e[v].push_back(node{u,i}); 
	}
	root=1;
	for(int i=1;i<=n;i++)sort(e[i].begin(),e[i].end(),cmp);
	dfs(1,0);
	int len=e[root].size();
	for(int x=0;x<=len;x++){
		int now=0;
		ll tmp=1;
		for(;now<x;now++)tmp=tmp*dp[e[root][now].to][1]%mod;
		for(;now<len;now++)tmp=tmp*dp[e[root][now].to][0]%mod;
		ans=(ans+tmp)%mod;
	}
	printf("%lld",(ans+mod)%mod);
	return 0;
}

