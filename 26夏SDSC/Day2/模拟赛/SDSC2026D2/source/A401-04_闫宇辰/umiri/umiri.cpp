#include<iostream>
#include<set>
#include<queue> 
#define MOD 1000000007
#define N 3000010 
#define INF 11451419198100000
using namespace std;
long long n,m,a[N];
int main(){
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	cin>>n>>m;
	for(int o=1;o<=m;++o){
		long long x,y;
		cin>>x>>y;
		while(y--){
			long long minn=INF;
			for(int i=1;i<=x;++i){
				minn=min(minn,a[i]);
			}
			for(int i=1;i<=x;++i){
				if(minn==a[i]){
					++a[i];
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		cout<<a[i]<<endl;
	}
	return 0;
} 
/*
7 -1 8 -4 2 6 -7 0

*/
