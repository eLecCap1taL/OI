#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5,INF=9e18,mod=998244353;
int n;
struct Node{int v,w;};
vector<Node>tr[N];
struct Edge{int u,v;}e[N];
bool vis[N];
int ind[N];
int ans;
bool bfs(){
	queue<pair<int,int> >q;
	for(int i=1;i<=n;i++){
		if(ind[i]==0) q.push({i,INF});
	}
	while(!q.empty()){
		int u=q.front().first,lstw=q.front().second;
		q.pop();
		for(auto ed:tr[u]){
			int v=ed.v,w=ed.w;
			if(w>lstw) return 0;
			if(--ind[v]==0) q.push({v,w});
		}
	}
	return 1;
}
void solve1(){
	for(int i=0;i<(1<<n-1);i++){
		for(int j=1;j<=n;j++){
			ind[j]=0; tr[j].clear();
		}
		for(int j=0;j<n-1;j++){
			if((i>>j)&1){
				tr[e[j+1].u].push_back({e[j+1].v,j+1});
				ind[e[j+1].v]++;
			}
			else{
				tr[e[j+1].v].push_back({e[j+1].u,j+1});
				ind[e[j+1].u]++;
			}
		}
		if(bfs()) ans=(ans+1)%mod;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>e[i].u>>e[i].v;
	}
	if(n<=15) solve1();
	return 0;
}
