#include<iostream>
#include<bitset>
#include<algorithm>
#include<queue> 
#include<ctime>
#include<cstdlib>
#define MOD 998244353
#define N 500010 
#define INF 1145141919810000
using namespace std;
long long n,m,a[510][510];
bitset<500> flag[510][510][20];
bool chk(long long x,long long y,long long k){
	long long cnt=-1,xx=x+k-1,yy=y+k-1;
	while(k){
		k>>=1;
		++cnt;
	}
	xx=xx-(1<<cnt)+1;
	yy=yy-(1<<cnt)+1;
	bitset<500>tk;
	tk=flag[x][y][cnt]|flag[xx][y][cnt]|flag[x][yy][cnt]|flag[xx][yy][cnt];
	return tk.count()<=m;
}
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			flag[i][j][0][a[i][j]]=1;
		}
	}
	for(int k=1;k<=10;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				long long tk=(1<<(k-1));
				if(i+tk*2-1<=n&&j+tk*2-1<=n){
					flag[i][j][k]=flag[i][j][k-1]|flag[i+tk][j][k-1]|flag[i][j+tk][k-1]|flag[i+tk][j+tk][k-1];
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			long long l=1,r=min(n-i+1,n-j+1);
			while(l<r){
				long long mid=(l+r+1)/2;
				if(chk(i,j,mid)){
					l=mid;
				}
				else{
					r=mid-1;
				}
			}
			cout<<l<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
/*
5 4
1 2 3 3 2 4 5 1 3 1 2 3 5 5 5 5 3 1 2 3 3 3 3 1 2
6 5
3 3 5 1 2 3 1 5 6 3 1 4 1 3 6 2 3 5 3 5 6 5 3 6 5 3 6 5 5 2 3 2 6 3 2 1
*/
