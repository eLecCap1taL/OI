#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;	
ll n,mx=1e9,my=1e9,xx=-1e9,xy=-1e9;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(ll i=1,x,y;i<=n;i++){
		cin>>x>>y;
		mx=min(mx,x);
		xx=max(xx,x);
		my=min(my,y);
		xy=max(xy,y);
	}
	cout<<mx-1<<" "<<xy+1<<"\n";
	cout<<xx+1<<" "<<my-1<<"\n";
	return 0;
}
