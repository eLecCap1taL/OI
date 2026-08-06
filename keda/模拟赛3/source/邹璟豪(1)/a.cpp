#include<bits/stdc++.h>
#define int long long 
using namespace std;
int x,y;
double s1,s2;
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>x>>y;
	int n=y+2*x;
	for(int i=1;i<=n;i++) s1+=(1.0/i);
	for(int i=1;i<=x;i++) s2+=(1.0/i);
	cout<<fixed<<setprecision(16)<<s1-0.5*s2;
}
