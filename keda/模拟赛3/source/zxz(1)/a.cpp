#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,n;
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>x>>y;
	n=2*x+y;
	long double hn=0.0,hx=0.0;
	for(int i=1;i<=n;i++)
		hn+=1.0/(long double)i;
	for(int i=1;i<=x;i++)
		hx+=1.0/(long double)i;
	cout<<fixed<<setprecision(15)<<hn-hx*0.500000000;
	return 0;
}
