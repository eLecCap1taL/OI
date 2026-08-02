#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
pair<int,int> e[500010];
vector<pair<int,int> > g[500010];
bool flag;
int n;
void dfs(int x,int ed,int lst){
	if(!flag)return;
	if(ed>=n)return;
	if(g[x].size()==0)return;
	for(auto v:g[x]){
		if(v.second>lst){
			flag=0;
			return;
		}
		dfs(v.first,ed+1,v.second);
	}
	if(g[x].size()==0)return;
} 
signed main(){
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	cin>>n;
	int ans=0;
	bool fl=1,fll=1;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[i]={u,v};
		if(max(u,v)!=n){
			fl=0;
		}
		if(max(u,v)!=i+1||min(u,v)!=i){
			fll=0;
		}
	}
	if(fll||fl){
		cout<<((1<<(n-1))-(n-2)*(n-1)/2)%mod;
		return 0;
	}
	for(int i=0;i<(1<<(n-1));i++){
		for(int j=1;j<=n;j++){
			g[j].clear();
		}
		for(int j=1;j<n;j++){
			if(i&(1<<(j-1))){
				g[e[j].first].push_back({e[j].second,j});
			}else{
				g[e[j].second].push_back({e[j].first,j});
			}
		}
		flag=1;
		for(int j=1;j<=n;j++){
			dfs(j,0,1000000000000000);
		}
		ans+=flag;
		ans%=mod; 
	}
	cout<<ans;
	return 0;
}
