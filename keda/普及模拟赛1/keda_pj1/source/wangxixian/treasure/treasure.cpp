#include<bits/stdc++.h>
#define ll long long
#define u64 unsigned long long

using namespace std;
string s;
int n,m,lin;
char a[110][110];
int vis[110][110],sum;
int xp[]={-1,0,1,0,-1,-1,1,1};
int yp[]={0,1,0,-1,-1,1,1,-1};
void dfs(int x,int y,int cnt,int fl,int cs){
	if(cs>1)return ;
	if(a[x][y]!=s[cnt])return ;
	if(cnt==lin-1){
		sum++;
		return ;
	}
//	cout<<x<<' '<<y<<' '<<a[x][y]<<endl;
	vis[x][y]=1;
	for(int i=0;i<8;i++){
		int nx=x+xp[i],ny=y+yp[i];
		if(vis[nx][ny]||nx<1||ny<1||nx>n||ny>m)continue;
		if(fl<0)dfs(nx,ny,cnt+1,i,cs);
		else{
			if(0<=i&&i<4&&fl>4&&fl<8)continue;
			if(0<=fl&&fl<4&&i>4&&i<8)continue;
			int gw=0;
			if(abs(i-fl)==1||abs(i-fl)==3)gw=1;
			dfs(nx,ny,cnt+1,i,cs+gw);
		}
	}
	return ;
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>s>>n>>m;
	lin=s.size();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			memset(vis,0,sizeof vis);
			dfs(i,j,0,-1,0);
		}
	}
	cout<<sum;
	return 0;
}

