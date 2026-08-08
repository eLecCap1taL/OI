#include<bits/stdc++.h>
using namespace std;
const int N=455;
const long long INF=1e18;
int n,a[N],siz[N];
long long f[N][N][2],g[N][2];
vector <int> v[N];
void dfs(int u)
{
	siz[u]=1;
	f[u][0][0]=f[u][1][1]=0;
	for(int i=0;i<v[u].size();i++)
	{
		int v2=v[u][i];
		dfs(v2);
		siz[u]+=siz[v2];
		for(int j=0;j<=siz[u];j++) g[j][0]=g[j][1]=-INF;
		for(int j=0;j<=siz[u]-siz[v2];j++)
		{
			for(int s1=0;s1<=1;s1++)
			{
				if(f[u][j][s1]==-INF) continue;
				for(int k=0;k<=siz[v2];k++)
				{
					for(int s2=0;s2<=1;s2++)
					{
						if(f[v2][k][s2]==-INF) continue;
						if(s1==s2) g[j+k][s1]=max(g[j+k][s1],f[u][j][s1]+f[v2][k][s2]+a[v2]);
						else g[j+k][s1]=max(g[j+k][s1],f[u][j][s1]+f[v2][k][s2]);
					}
				}
			}
		}
		for(int j=0;j<=siz[u];j++) f[u][j][1]=g[j][1],f[u][j][0]=g[j][0];
	}
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++) f[i][j][0]=f[i][j][1]=-INF;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("still.in","r",stdin);
	freopen("still.out","w",stdout);
	cin>>n;
	init();
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(2*i<=n) v[i].push_back(2*i);
		if(2*i+1<=n) v[i].push_back(2*i+1);
	}
	dfs(1);
	cout<<max(f[1][n/2][0],f[1][n/2][1]);
}
/*
6
14 10 -7 -50 -50 20
*/
