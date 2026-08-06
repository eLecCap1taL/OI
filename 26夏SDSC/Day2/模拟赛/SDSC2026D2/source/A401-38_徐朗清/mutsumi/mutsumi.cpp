#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<iomanip>
#include<set>
#define ll long long
using namespace std;
const int N=15;
int n,ans,a[N],vis[N];
void dfs(int cnt){
	int b[N],top;
	ans=max(ans,cnt);
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		b[++top]=i;
	}
	for(int i=1;i<top;i++){
		int val=a[b[i]];
		if(val==i){
			vis[b[i]]=vis[b[i+1]]=1;
			dfs(cnt+1);
			vis[b[i]]=vis[b[i+1]]=0;
		}
	}
}
int main() {
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
