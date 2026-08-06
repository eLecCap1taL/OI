#include<bits/stdc++.h>
#define int long long
#define mkp make_pair
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=15;
int n,a[N],ans;
void dfs(int dep,vector<int> vec){
	ans=max(ans,dep);
	for(int i=0;i<(int)vec.size()-1;i++){
		if(vec[i]==i+1){
			vector<int> nxt;
			for(int j=0;j<i;j++) nxt.push_back(vec[j]);
			for(int j=i+2;j<(int)vec.size();j++) nxt.push_back(vec[j]);
			dfs(dep+1,nxt);
		}
	}
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	cin>>n;
	vector<int> vec;
	for(int i=1;i<=n;i++) cin>>a[i],vec.push_back(a[i]);
	dfs(0,vec);cout<<ans;
	return 0;
}
