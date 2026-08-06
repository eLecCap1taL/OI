#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=810;
int a[N],ans=0,n;
bool flag[55];
void dfs(int x){
	ans=max(ans,x);
	if(x>n/2)return;
	int cnt=0;
	for(int i=1;i<n;i++){
		if(flag[i]){
			cnt++;
			continue;
		}
		int nxt=0;
		for(int j=i+1;i<=n;j++){
			if(flag[j])continue;
			nxt=j;
			break;
		}
		if(!nxt)break;
		if(i-cnt==a[i]){
			flag[i]=flag[nxt]=1;
			dfs(x+1);
			flag[i]=flag[nxt]=0;
		}
	}
}
int main(){
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=50){
		dfs(0);
		printf("%d",ans);
	}
	else printf("%d",n/3);
	return 0;
}

