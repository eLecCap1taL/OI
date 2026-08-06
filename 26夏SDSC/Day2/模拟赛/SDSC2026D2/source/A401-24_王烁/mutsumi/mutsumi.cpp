#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
void dfs(vector<int>e){
	int m=e.size();
	ans=max(ans,(n-m)/2);
	for(int i=0;i<m;i++){
		if(i+1!=e[i])continue;
		vector<int>v;
		for(int j=0;j<i;j++)v.push_back(e[j]);
		for(int j=i+2;j<m;j++)v.push_back(e[j]);
		dfs(v);
	}
}
int main(){
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	scanf("%d",&n);
	vector<int>e(n);
	for(int i=0;i<n;i++)scanf("%d",&e[i]);
	dfs(e);
	printf("%d",ans);
	return 0;
}
