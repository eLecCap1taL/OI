#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 510;
int n,m,a[maxn][maxn],ans[maxn][maxn];
int cnt[maxn],tot;

void add(int x,int y,int xx,int yy)
{
	for(int i = y;i <= yy;i++) if(++cnt[a[xx][i]] == 1) tot++;
	for(int i = x;i < xx;i++) if(++cnt[a[i][yy]] == 1) tot++;
}
void del(int x,int y,int xx,int yy)
{
	for(int i = y;i <= yy;i++) if(--cnt[a[x][i]] == 0) tot--;
	for(int i = x + 1;i <= xx;i++) if(--cnt[a[i][y]] == 0) tot--;	
} 

void sol(int x,int y)
{
	for(int i = 1;i <= n;i++) cnt[i] = 0;
	ans[x][y] = 1; cnt[a[x][y]]++; tot = 1;
	
	while(x + ans[x][y] <= n && y + ans[x][y] <= n)
	{
		add(x,y,x+ans[x][y],y+ans[x][y]);
		if(tot > m) break;
		ans[x][y]++;
	}
	
	for(int i = 1;x + i <= n && y + i <= n;i++)
	{
		int nx = x + i,ny = y + i;
		ans[nx][ny] = ans[nx-1][ny-1] - 1;
		del(nx - 1,ny - 1,nx+ans[nx][ny],ny+ans[nx][ny]);
		if(tot > m || nx + ans[nx][ny] > n || ny + ans[nx][ny] > n) continue;
		
		ans[nx][ny]++;
		while(nx + ans[nx][ny] <= n && ny + ans[nx][ny] <= n)
		{
			add(nx,ny,nx + ans[nx][ny],ny + ans[nx][ny]);
			if(tot > m) break;
			ans[nx][ny]++;
		}
	}
}

signed main()
{
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) cin >> a[i][j];
	for(int i = 1;i <= n;i++) sol(1,i);
	for(int i = 2;i <= n;i++) sol(i,1);
	for(int i = 1;i <= n;i++) 
	{
		for(int j = 1;j <= n;j++) cout << ans[i][j] << " ";
		cout << '\n';
	}
	return 0;
} 
