#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int vis[505][505][505];
int ans[505][505];
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	int n,kk;
	scanf("%d %d",&n,&kk);
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			maxx=max(maxx,a[i][j]);
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j>=1;j--){
			for(int k=1;k<=maxx;k++){
				vis[i][j][k]=vis[i][j+1][k]+vis[i+1][j][k]-vis[i+1][j+1][k];
				vis[j][i][k]=vis[j+1][i][k]+vis[j][i+1][k]-vis[j+1][i+1][k];
			}
			vis[i][j][a[i][j]]++;
			if(i!=j){
				vis[j][i][a[j][i]]++;
			}
			int l=1,r=min(n-i+1,n-j+1);
			int len=0;
			while(l<=r){
				int mid=(l+r)/2;
				int youx=i+mid-1;
				int youy=j+mid-1;
				int cnt=0;
				for(int k=1;k<=maxx;k++){
					if(vis[i][j][k]-vis[youx+1][j][k]-vis[i][youy+1][k]+vis[youx+1][youy+1][k]){
						cnt++;
					}
				}
				if(cnt<=kk){
					len=mid;
					l=mid+1;
				}
				else{
					r=mid-1;
				}
			}
			ans[i][j]=len;
			if(i!=j){
				l=1,r=min(n-i+1,n-j+1);
				len=0;
				while(l<=r){
					int mid=(l+r)/2;
					int youx=j+mid-1;
					int youy=i+mid-1;
					int cnt=0;
					for(int k=1;k<=maxx;k++){
						if(vis[j][i][k]-vis[youx+1][i][k]-vis[j][youy+1][k]+vis[youx+1][youy+1][k]){
							cnt++;
						}
					}
					if(cnt<=kk){
						len=mid;
						l=mid+1;
					}
					else{
						r=mid-1;
					}
				}
				ans[j][i]=len;
			}
//			if(i==1&&j==1||i==2&&j==1){
//				int youx=i+ans[i][j]-1;
//				int youy=j+ans[i][j]-1;
//				for(int k=1;k<=maxx;k++){
//					printf("%d ",vis[i][j][k]-vis[youx+1][j][k]-vis[i][youy+1][k]+vis[youx+1][youy+1][k]);
//				}
//				printf("\n");
//			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
