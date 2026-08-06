#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];vector<int> s;
int vis[200010],stk[200010];
void solve(){
	int n,k,m;
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		a[i]=i;
		vis[i]=0;
	}
	s.clear();
	for(int i=1;i<=m;i++){
		cin>>b[i];vis[b[i]]=1;
	}
	if(k==3){
		if((n-m)&1){
			cout<<"NO\n";
			return;
		}else{
			cout<<"YES\n";
		}
	}
}
signed main(){
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
