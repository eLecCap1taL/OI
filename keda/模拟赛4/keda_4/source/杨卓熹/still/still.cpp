#include<iostream>
#include<cmath>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=505;
const ll inf=1e18;
ll n,a[maxn];
ll head[maxn],nxt[maxn<<1],to[maxn<<1],cnt=0;
ll siz[maxn];
ll f[maxn][maxn][2],g[maxn][2];
//f:以i为根的子树中选j个1且i选不选1的最大分数 
inline void adde(ll u,ll v)
{
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
inline void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++) 
		{
			f[i][j][0]=f[i][j][1]=-inf;	
		}
	}
}
inline void init1(ll u,ll v)
{
	for(int i=0;i<=siz[u]+siz[v];i++) g[i][0]=g[i][1]=-inf;
}
inline void dfs(ll u,ll fa)
{
	siz[u]=1;
	f[u][1][1]=f[u][0][0]=0;
	for(int i=head[u];i;i=nxt[i]) 
	{
		ll v=to[i];
		if(v==fa) continue;
		dfs(v,u);
		init1(u,v);
		for(int j=0;j<=siz[u];j++)
		{
			for(int k=0;k<=1;k++)
			{
				if(f[u][j][k]==-inf) continue;
				for(int l=0;l<=siz[v];l++)
				{
					for(int p=0;p<=1;p++)
					{
						if(f[v][l][p]==-inf) continue;
						if(k==p) g[j+l][k]=max(g[j+l][k],f[u][j][k]+f[v][l][p]+a[v]);
						else g[j+l][k]=max(g[j+l][k],f[u][j][k]+f[v][l][p]);
					}
				}
			}
		}
		for(int j=0;j<=siz[u]+siz[v];j++)
		{
			f[u][j][0]=g[j][0];
			f[u][j][1]=g[j][1];
		}
		siz[u]+=siz[v];
	}
}
inline void fre()
{
	freopen("still.in","r",stdin);
	freopen("still.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>n;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		adde(i,i/2);
		adde(i/2,i);
	}
	dfs(1,0);
	cout<<max(f[1][n/2][0],f[1][n/2][1]);
	return 0;
}
