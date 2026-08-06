#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=35,MOD=1e9+7;
int n,m,f[N][N],g[N][N];
bool crop[N][N];
char ch[N][N]; 
void solvea()
{
	int cntt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) if(ch[i][j]=='-') cntt++;
	}
	int U=(1ll<<cntt)-1,cnt=0;
	for(int zt=0;zt<=U;zt++)
	{
		int tot=0; 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				crop[i][j]=0;
				if(ch[i][j]=='#') continue;
				tot++;
				if(zt&(1<<(tot-1))) crop[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++) f[i][0]=f[0][i]=-1e9,g[i][0]=g[0][i]=1e9;
		f[1][1]=(crop[1][1]==1);
		g[1][1]=(crop[1][1]==1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1 && j==1) continue;
				f[i][j]=-1e9,g[i][j]=1e9;
				if(ch[i][j]=='#') continue;
				f[i][j]=max(f[i-1][j],f[i][j-1])+crop[i][j];
				g[i][j]=min(g[i-1][j],g[i][j-1])+crop[i][j];
			}
		}
		if(f[n][m]<0 || (f[n][m]==1 && g[n][m]==1)) cnt++;
	}
	cout<<cnt;
}
signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>m;
	bool fl=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ch[i][j];
			if(ch[i][j]=='#') fl=0;
		}
	}
	if(fl) cout<<n+m-1;
	else solvea();
}
