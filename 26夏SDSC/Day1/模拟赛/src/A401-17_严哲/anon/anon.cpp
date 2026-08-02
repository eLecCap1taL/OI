#include<bits/stdc++.h>
#define int long long
#define mkp make_pair
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=505;
bool st;
int n,K,a[N][N],ans[N][N],vis[N][N];
bitset<N> f[2][N][N];
bool ed;
namespace Subtask{
	int sum[N][N][3];
	void solve(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				sum[i][j][1]=sum[i-1][j][1]+sum[i][j-1][1]-sum[i-1][j-1][1]+(a[i][j]==1);
				sum[i][j][2]=sum[i-1][j][2]+sum[i][j-1][2]-sum[i-1][j-1][2]+(a[i][j]==2);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int len=1;i+len-1<=n&&j+len-1<=n;len++){
					int x=i+len-1,y=j+len-1;
					int num=0;
					for(int k=1;k<=2;k++){
						if(sum[x][y][k]-sum[i-1][y][k]-sum[x][j-1][k]+sum[i-1][j-1][k]>0) num++;
					}
					if(num<=K) ans[i][j]=len;
					else break;
				}
				cout<<ans[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
};
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin>>n>>K;int maxV=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			f[1][i][j][a[i][j]]=1;
			ans[i][j]=1;
			maxV=max(maxV,a[i][j]);
		}
	}
	if(maxV<=2) {Subtask::solve();return 0;}
	vector<pii> vec;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			vec.push_back(mkp(i,j)),vis[i][j]=1;
	}
	for(int k=2;k<=n;k++){
		vector<pii> nxt;
		for(pii now:vec){
			int x=now.first,y=now.second;
			if(vis[x][y]&&vis[x-1][y]&&vis[x][y-1]){
				f[k&1][x-1][y-1]=f[(k&1)^1][x-1][y]|f[(k&1)^1][x][y-1]|f[(k&1)^1][x][y]|f[(k&1)^1][x-1][y-1];
				if(((int)f[k&1][x-1][y-1].count())<=K) nxt.push_back(mkp(x-1,y-1)),ans[x-1][y-1]=k;
			}
		}
		for(pii now:vec){
			int x=now.first,y=now.second;
			f[(k&1)^1][x][y]=0;vis[x][y]=0;
		}
		for(pii now:nxt) vis[now.first][now.second]=1;
		vec=nxt;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}
