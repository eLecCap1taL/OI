#include<iostream>
#include<bitset>
#include<algorithm>
#include<queue> 
#include<ctime>
#include<cstdlib>
#define MOD 1145141
#define N 500010 
#define INF 1145141919810000
using namespace std;
int main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		long long d,n,a,fac=1;
		cin>>d>>n>>a;
		for(int i=0;i<n&&fac;++i){
			fac=fac*(a+i*d%MOD)%MOD;
		}
		cout<<fac<<endl;
	}
	return 0;
} 
/*
5 4
1 2 3 3 2 4 5 1 3 1 2 3 5 5 5 5 3 1 2 3 3 3 3 1 2
6 5
3 3 5 1 2 3 1 5 6 3 1 4 1 3 6 2 3 5 3 5 6 5 3 6 5 3 6 5 5 2 3 2 6 3 2 1
*/
