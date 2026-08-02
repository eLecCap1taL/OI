#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=510;
const int oo=1e17;
int a[maxn][maxn],sum[maxn][maxn][maxn];
int V=-1;
int n,k;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
bool check(int i,int j,int u,int v){
	int tot=0;
	for(int c=1;c<=V;c++){
		if(sum[c][u][v]-sum[c][i-1][v]-sum[c][u][j-1]+sum[c][i-1][j-1]>0)tot++;
		if(tot>k)return 0;
	}
	return tot<=k;
} 
signed main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			V=max(V,a[i][j]);
		}
	}
	for(int c=1;c<=V;c++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				sum[c][i][j]=sum[c][i-1][j]+sum[c][i][j-1]+(a[i][j]==c)-sum[c][i-1][j-1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int l=1,r=min(n-i+1,n-j+1);
			int ssss=1;
			while(l<=r){
				int mid=l+r>>1;
				int u=i+mid-1;
				int v=j+mid-1;
				if(check(i,j,u,v)){
					l=mid+1;
					ssss=mid;
				}else{
					r=mid-1;
				}
			}
			cout<<ssss<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
