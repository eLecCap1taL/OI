#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[300005];
int pro[300005],nex[300005],head[300005],quan[300005],cnt=-1;
bool vis[300005];
bool flag=1;
void ll(int x,int y,int z){
	pro[++cnt]=y;
	nex[cnt]=head[x];
	quan[cnt]=z;
	head[x]=cnt;
}
void dfs(int x,int shang,int zong,int step){
	vis[x]=1;
//	if(head[x]==-1){
//		printf("%d %d\n",zong,step-1);
//		if(step>1&&zong==step-1){
//			flag=0;
//			return ;
//		}
//	}
	for(int i=head[x];i!=-1;i=nex[i]){
		int y=pro[i];
		if(quan[i]>shang){
			flag=0;
		}
		dfs(y,quan[i],quan[i]>shang?zong+1:zong,step+1);
	}
}
int main(){
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	long long ans=0;
	for(int i=0;i<(1<<(n-1));i++){
		cnt=-1;
//		printf("%d\n",i);
		flag=1;
		for(int j=1;j<=n;j++){
			head[j]=-1;
			vis[j]=false;
		}
		for(int j=1;j<n;j++){
			if((i>>(j-1))&1){
				ll(a[j].x,a[j].y,j);
			}
			else{
				ll(a[j].y,a[j].x,j);
			}
		}
		for(int j=1;j<=n;j++){
			if(!flag){
				break;
			}
			if(!vis[j]){
				dfs(j,0x3f3f3f3f,0,1);
			}
		}
		if(flag){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
} 
