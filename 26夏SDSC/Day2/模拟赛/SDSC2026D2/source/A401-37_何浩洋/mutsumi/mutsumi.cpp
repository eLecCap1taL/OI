#include<bits/stdc++.h>
using namespace std;
int ans,a[809],n;
void dfs(int p,int s) {
	ans=max(ans,s);
	for(int i=1; i<p; i++) {
		if(a[i]==i) {
			int c=a[i+1],d[809];
			int k=1;
			for(int j=1; j<=p; j++)
				d[j]=a[j];
			for(int j=1; j<=p-2; j++) {
				if(k==i) k+=2;
				a[j]=a[k++];
			}
			dfs(p-2,s+1);
			for(int j=1; j<=p; j++)
				a[j]=d[j];
		}
	}
}
int main() {
    freopen("mutsumi.in","r",stdin);
    freopen("mutsumi.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	dfs(n,0);
	cout<<ans;
	return 0;
}

