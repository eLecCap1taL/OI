#include<bits/stdc++.h>
#define N 2000010
using namespace std;
int n,k,m,b[N],bk[N],s0[N];
bool can;
void dfs(vector<int>e,vector<int>t){
	if(can)return;
	if(e==t){can=1;return;}
	for(int i=1;i<n-1;i++){
		if(e[i]==-1)continue;
		for(int l=0;l<i;l++){
			if(e[l]!=0)continue;
			for(int r=i+1;r<n;r++){
				if(e[r]!=0)continue;
				vector<int>v=e;
				v[l]=v[r]=-1;
				dfs(v,t);
				if(can)return;
			}
		}
	}
}
int main(){
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&m);
		bool flag=1;
		if((n-m)%(k-1))flag=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			if(b[i]==b[i-1]||b[i]>n)flag=0;
			else bk[b[i]]=1;
		}
		if(!flag)puts("NO");
		else if(n<=6&&k==3){
			can=0;
			vector<int>s(n),t(n);
			for(int i=0;i<n;i++){
				if(bk[i+1])t[i]=1,s[i]=1;
				else t[i]=-1,s[i]=0;
			}
			dfs(s,t);
			if(can)puts("YES");
			else puts("NO");
		}else{
			for(int i=1;i<=n;i++)s0[i]=s0[i-1]+(bk[i]==0);
			int tim=(n-m)/(k-1);
			if(!tim)puts("YES");
			else if(tim==1){
				bool yes=0;
				for(int i=1;i<=n;i++){
					if(!bk[i])continue;
					if(s0[i-1]*2==n-m){yes=1;break;}
				}
				if(yes)puts("YES");
				else puts("NO");
			}else if(tim==2){
				bool yes=0;
				for(int i=1;i<=n;i++){
					if(!bk[i])continue;
					if(s0[i-1]>=k/2&&n-m-s0[i]>=k/2){yes=1;break;}
				}
				if(yes)puts("YES");
				else puts("NO");
			}else puts("NO");
		}
	}
	return 0;
}
