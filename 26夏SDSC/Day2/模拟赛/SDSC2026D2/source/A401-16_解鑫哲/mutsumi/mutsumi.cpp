#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 802;
int n,a[N],vis[N],d[N],ans;
void dfs(int i,int del,int back){
	ans = max(ans,del);
	vis[i] = true;
	int b = 0;
	for(int j = 1;j <= n;j++){
		if(d[j])	b++;
		if(!vis[j])
			dfs(j,del,b);
	}
	b = 0;
	if(a[i] == i-back){
		int io = -1,lavis = 0;
		for(int j = i+1;j <= n;j++)
			if(!d[j])	{io=j;break;}
//		printf("Back to io(%d)\n",io);
		if(io == -1)	return;
		lavis = vis[io];
		d[i] = d[io] = true;
		vis[io] = true;
		for(int j = 1;j <= n;j++){
			if(d[j])	b++;
			if(!vis[j])
				dfs(j,del+1,b);
		}
		d[i] = d[io] = false;
		vis[io] = lavis;
	}
	vis[i] = false;
	return;
}
int main(){
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n;i++)
		dfs(i,0,0);
	printf("%d",ans);
	return 0;
}
/*
5
1 3 1 5 5

8
1 2 3 8 8 8 8 8
*/
