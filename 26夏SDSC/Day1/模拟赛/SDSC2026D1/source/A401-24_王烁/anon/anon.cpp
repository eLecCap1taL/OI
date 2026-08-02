//thousand mourning love music 
#include<bits/stdc++.h>
#define N 510
using namespace std;
int n,k,a[N][N],bk[N],f[N][N];
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++){//left vertical
		memset(bk,0,sizeof(bk));
		int cnt=0;
		for(int l=1,r=0;i+l-1<=n;l++){
			f[i+l-1][l]=max(f[i+l-1][l],r-l+1);
			while(cnt<=k&&i+r-1<n){
				r++;
				int ncnt=cnt;
				for(int x=i+l-1;x<=i+r-1;x++){
					bk[a[x][r]]++;
					if(bk[a[x][r]]==1)ncnt++;
				}
				for(int x=l;x<r;x++){
					bk[a[i+r-1][x]]++;
					if(bk[a[i+r-1][x]]==1)ncnt++;
				}
				if(ncnt>k){
					for(int x=i+l-1;x<=i+r-1;x++)bk[a[x][r]]--;
					for(int x=l;x<r;x++)bk[a[i+r-1][x]]--;
					r--;
					break;
				}else{
					cnt=ncnt;
					f[i+l-1][l]=max(f[i+l-1][l],r-l+1);
				}
			}
			for(int x=l;x<=r;x++){
				bk[a[i+l-1][x]]--;
				if(bk[a[i+l-1][x]]==0)cnt--;
			}
			for(int x=i+l;x<=i+r-1;x++){
				bk[a[x][l]]--;
				if(bk[a[x][l]]==0)cnt--;
			}
		}
	}
	for(int i=2;i<=n;i++){//up horizontal
		memset(bk,0,sizeof(bk));
		int cnt=0;
		for(int l=1,r=0;i+l-1<=n;l++){
			f[l][i+l-1]=max(f[l][i+l-1],r-l+1);
			while(cnt<=k&&i+r-1<n){
				r++;
				int ncnt=cnt;
				for(int x=l;x<=r;x++){
					bk[a[x][i+r-1]]++;
					if(bk[a[x][i+r-1]]==1)ncnt++;
				}
				for(int x=i+l-1;x<i+r-1;x++){
					bk[a[r][x]]++;
					if(bk[a[r][x]]==1)ncnt++;
				}
				if(ncnt>k){
					for(int x=l;x<=r;x++)bk[a[x][i+r-1]]--;
					for(int x=i+l-1;x<i+r-1;x++)bk[a[r][x]]--;
					r--;
					break;
				}else{
					cnt=ncnt;
					f[l][i+l-1]=max(f[l][i+l-1],r-l+1);
				}
			}
			for(int x=i+l-1;x<=i+r-1;x++){
				bk[a[l][x]]--;
				if(bk[a[l][x]]==0)cnt--;
			}
			for(int x=l+1;x<=r;x++){
				bk[a[x][i+l-1]]--;
				if(bk[a[x][i+l-1]]==0)cnt--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%d ",f[i][j]);
		puts("");
	}
	return 0;
}
