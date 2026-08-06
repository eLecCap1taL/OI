#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e6+10,mod=1145141;
ll t,n,k,m,cnt,a[N];
int main(){
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>m;
		a[0]=0;a[m+1]=n+1;
		for(ll i=1;i<=m;i++){
			cin>>a[i];
		}
		if(n==m){
			cout<<"Yes\n";
			continue;
		}
		if((n-m)%(k-1)){
			cout<<"No\n";
			continue;
		}
		cnt=(n-m)/(k-1);
		ll i=0,j=0;
		while(a[i]+1==a[i+1])i++;
		while(a[m+1-j]==a[m-j]+1)j++;
		if(m-i-j==0){
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
	}
	return 0;
}
/*
4
7 3 3
1 5 7
3 3 1
1
13 7 7
1 3 5 7 9 11 12
10 5 3
4 5 6
*/
