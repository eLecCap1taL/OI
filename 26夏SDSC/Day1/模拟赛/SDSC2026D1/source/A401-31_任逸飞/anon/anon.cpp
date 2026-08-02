#include<bits/stdc++.h>
using namespace std;
const int max_n=502;
int n,m,a[max_n][max_n];
int cnt,ans[max_n][max_n],d[max_n],ape[max_n];
bool vis[max_n];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	//考虑优化 j 的循环。首先枚举 i，在扩展 (i,1) 的正方形时，记录是否成功。
	//若成功，则答案向后边正方形做贡献。若 (i,1) 扩展长度 k 成功，则将 k 加入贡献 
	//注意倒着枚举，方便写，速度快，如果某次扩展失败，就在扩展失败位置先自己向外扩展，再扩展其他正方形 
	if(n<=50){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vis[a[i][j]]=true;
				cnt=1;
				if(cnt>m){
					printf("%d ",0);
					continue;
				}
				ans[i][j]=1;
				for(int k=2;k<=min(n-j,n-i)+1;k++){
					for(int l=i;l<=i+k-1;l++){
						if(!vis[a[l][j+k-1]]){
							vis[a[l][j+k-1]]=true;
							cnt++;
						}
					}
					if(cnt>m){
						break;
					}
					for(int l=j;l<j+k-1;l++){
						if(!vis[a[i+k-1][l]]){
							vis[a[i+k-1][l]]=true;
							cnt++;
						}
					}
					if(cnt>m){
						break;
					}
					ans[i][j]=k;
				}
				printf("%d ",ans[i][j]);
				for(int k=1;k<=n;k++){
					vis[k]=false;
				}
			}
			puts("");
		}
	}
	else{
		//以右上角为起点枚举 
		for(int i=1;i<=n;i++){
			for(int j=n;j>=1;j--){
				cnt=0;
				bool f=true;
				int now=0;
				for(int k=1;k<=min(n-j,n-i)+1;k++){
					for(int l=i;l<=i+k-1;l++){
						if(!vis[a[l][j+k-1]]){
							vis[a[l][j+k-1]]=true;
							cnt++;
						}
					}
					if(cnt>m){
						break;
					}
					for(int l=j;l<j+k-1;l++){
						if(!vis[a[i+k-1][l]]){
							vis[a[i+k-1][l]]=true;
							cnt++;
						}
					}
					if(cnt>m){
						break;
					}
					ans[i][j]=k;
				}
				for(int k=1;k<=n;k++){
					vis[k]=false;
				}
				cnt=0;
				for(int k=2;k<=min(j,n-i+1);k++){
					for(int l=i;l<=i+k-1;l++){
						if(!vis[a[l][j-k+1]]){
							vis[a[l][j-k+1]]=true;
							cnt++;
						}
					}
					if(cnt>m){
						f=false;
						break;
					}
					for(int l=j;l>j-k+1;l--){
						if(!vis[a[i+k-1][l]]){
							vis[a[i+k-1][l]]=true;
							cnt++;
						}
					}
					if(cnt>m){
						f=false;
						break;
					}
					now=j-k+1;
					ans[i][j-k+1]=k;
				}
				for(int k=1;k<=n;k++){
					vis[k]=false;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
