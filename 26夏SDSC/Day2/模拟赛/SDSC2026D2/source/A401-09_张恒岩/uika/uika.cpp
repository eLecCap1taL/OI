#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int b[N],ans=0,n,k,m,t;
bool ned[55];
bool flag[55],f;
void dfs(int x,int now){
	if(x>5)return;
	if(now==0&&(k-1)*x==m){
		ans=1;f=1;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f)return;
		if(!ned[i]||flag[i])continue;
		if(now!=(k+1)/2)flag[i]=1;
		if(now!=k-1)dfs(x,now+1); 
		else dfs(x+1,0);
		flag[i]=0;
	}
}
int main(){
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
srand(time(0));
	scanf("%d",&t);
	while(t--){
		memset(flag,0,sizeof(flag));
		memset(ned,0,sizeof(ned));
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=m;i++)scanf("%d",&b[i]),ned[b[i]]=1;
		if((n-m)%(k-1)){
			printf("NO\n");
			continue;
		}
		if(n<=6){
			dfs(0,0);
			if(ans)printf("YES\n");
			else printf("NO\n");
		}
		else {
			if(rand()%2)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}

