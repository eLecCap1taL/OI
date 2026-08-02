#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 3e5+8;
const int MOD = 998244353;
int n;
struct Node
{
	int v,w;
};
struct A
{
	int u,v,w;
	bool operator <(const A&rhs)const{
		return w < rhs.w;
	}
};
A edg[MAXN];
vector<Node>adj[MAXN];
LL dp[MAXN][2];
void dfs(int u,int f,int w)
{
	bool flag = 1;
	LL res[3][3][2],cnt = 0,cnt1 = 0,cnt0 = 0;
	for(int i = 0;i < 3;i++)for(int j = 0;j < 3;j++)res[i][j][0] = res[i][j][1] = 0;
	for(int i = 0;i < adj[u].size();i++)
	{
		Node n = adj[u][i];
		if(n.v == f)continue;
		dfs(n.v,u,n.w),cnt++;
		if(flag){
			if(w < n.w)res[2][0][cnt] = dp[n.v][1],res[0][2][cnt] = dp[n.v][0];
			else res[2][2][cnt] = dp[n.v][1],res[0][1][cnt] = dp[n.v][0];
			
		}
		else
		{
			if(w < n.w)
			{
				res[2][0][cnt&1] = (1ll*(res[2][0][(cnt-1)&1]+res[2][2][(cnt-1)&1])*dp[n.v][1])%MOD;
				res[0][2][cnt&1] = (1ll*(res[0][2][(cnt-1)&1]+res[2][2][(cnt-1)&1])*dp[n.v][0])%MOD;
				res[0][0][cnt&1] = (1ll*(res[0][0][(cnt-1)&1]+res[2][0][(cnt-1)&1])*dp[n.v][0])%MOD;
				res[0][1][cnt&1] = (1ll*res[0][1][(cnt-1)&1]*dp[n.v][0])%MOD;
			}
			else
			{
				res[2][2][cnt&1] = (1ll*res[2][2][(cnt-1)&1]*dp[n.v][1])%MOD,cnt1++;
				res[0][1][cnt&1] = (1ll*(res[2][2][(cnt-1)&1]+res[0][1][(cnt-1)&1])*dp[n.v][0])%MOD;
			}
			
		}
		flag = 0;		
	}
	dp[u][0] = (res[0][0][cnt&1]+res[2][0][cnt&1]+res[0][2][cnt&1]+res[2][2][cnt&1])%MOD;
	dp[u][1] = (res[0][1][cnt&1]+res[2][1][cnt&1]+res[0][2][cnt&1]+res[2][2][cnt&1])%MOD;
	if(flag)dp[u][0] = dp[u][1] = 1;
	//cout<<u<<" "<<dp[u][0] <<" "<< dp[u][1]<<"\n";
}
int main()
{
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	cin>>n;
	for(int i = 1,u,v;i < n;i++)cin>>u>>v,edg[i] = {u,v,i};
	sort(edg+1,edg+n);
	for(int i = 1,u,v;i < n;i++)adj[edg[i].u].push_back({edg[i].v,edg[i].w}),adj[edg[i].v].push_back({edg[i].u,edg[i].w});	
	dfs(1,0,0);
	cout<<dp[1][0];
	return 0;
} 
