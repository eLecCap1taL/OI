#include<bits/stdc++.h>
using namespace std;
int n,k,a[505][505];
bool vis[505];
int sum[505][505];
int ans[505][505];
bool check(int x,int y,int len){
	memset(vis,0,sizeof vis);
	int cnt=0;
	for(int i=x;i<=x+len-1;i++){
		for(int j=y;j<=y+len-1;j++){
			if(vis[a[i][j]]) continue;
			vis[a[i][j]]=1; cnt++;
		}
	}
	return cnt<=k;
}
void solve1(){
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			for(int len=min(n-x+1,n-y+1);len>=1;len--){
				if(check(x,y,len)){
					ans[x][y]=len; break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
}
void solve2(){
	if(k>=2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[i][j]=min(n-i+1,n-j+1);
			}
		}
	}
	else{
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				for(int len=min(n-x+1,n-y+1);len>=1;len--){
					int s=sum[x+len-1][y+len-1]-sum[x-1][y+len-1]-sum[x+len-1][y-1]+sum[x-1][y-1];
					if(s==len*len||s==len*len*2){
						ans[x][y]=len; break;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
}
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin>>n>>k;
	bool f2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
			if(a[i][j]>2) f2=1;
		}
	}
	if(n<=50) solve1();
	else if(!f2) solve2();
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<"1 ";
			}
			cout<<'\n';
		}
	}
	return 0;
}
