#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
int a[N][N],n,k;
int ans[N][N],cnt[N],tot;
bool flag1;
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>3)flag1=0;
		}
	if(k==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)printf("1 ");
			printf("\n");
		}
		return 0;
	}
	if(flag1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)printf("%d ",min(n-i+1,n-j+1));
			printf("\n");
		}
		return 0;
	}
	for(int i=1;i<=n;i++)ans[i][n]=ans[n][i]=1;
	for(int i=1;i<n;i++){
		int lx=n-1,ly=i;
		memset(cnt,0,sizeof(cnt));
		cnt[a[n][i+1]]++;tot=1;
		while(lx>0&&ly>0){
		//	printf("%d %d\n",lx,ly);
			int rx=lx+ans[lx+1][ly+1],ry=ly+ans[lx+1][ly+1];
			for(int i=lx;i<=rx;i++){
				cnt[a[i][ly]]++;
				if(cnt[a[i][ly]]==1)tot++;
			}
			for(int j=ly+1;j<=ry;j++){
				cnt[a[lx][j]]++;
				if(cnt[a[lx][j]]==1)tot++;
			}
			while(tot>k){
				for(int i=lx;i<=rx;i++){
					cnt[a[i][ry]]--;
					if(cnt[a[i][ry]]==0)tot--;
				}
				for(int j=ly;j<ry;j++){
					cnt[a[rx][j]]--;
					if(cnt[a[rx][j]]==0)tot--;
				}
				rx--;ry--;
			//	printf("	%d %d %d\n",rx,ry,tot);
			}
			ans[lx][ly]=rx-lx+1;
			lx--;ly--;
		}
	}
	for(int i=1;i<n;i++){
		int lx=i,ly=n-1;
		memset(cnt,0,sizeof(cnt));
		cnt[a[i+1][n]]++;tot=1;
		while(lx>0&&ly>0){
		//	printf("%d %d\n",lx,ly);
			int rx=lx+ans[lx+1][ly+1],ry=ly+ans[lx+1][ly+1];
			for(int i=lx;i<=rx;i++){
				cnt[a[i][ly]]++;
				if(cnt[a[i][ly]]==1)tot++;
			}
			for(int j=ly+1;j<=ry;j++){
				cnt[a[lx][j]]++;
				if(cnt[a[lx][j]]==1)tot++;
			}
			while(tot>k){
				for(int i=lx;i<=rx;i++){
					cnt[a[i][ry]]--;
					if(cnt[a[i][ry]]==0)tot--;
				}
				for(int j=ly;j<ry;j++){
					cnt[a[rx][j]]--;
					if(cnt[a[rx][j]]==0)tot--;
				}
				rx--;ry--;
		//		printf("	%d %d %d\n",rx,ry,tot);
			}
			ans[lx][ly]=rx-lx+1;
			lx--;ly--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}

