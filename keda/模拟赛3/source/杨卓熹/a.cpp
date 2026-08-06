#include<iostream>
#include<cmath>
#include<iomanip>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll x,y,n;
double m=0,ans=0,sum=0;
inline void fre()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>x>>y;
	n=2*x+y;
	for(int i=1;i<=n;i++)
	{
		ans+=1.0/i;
		if(i==x) sum=ans;
	}
	cout<<fixed<<setprecision(16)<<(double)(ans-sum*1.0/2);
	return 0; 
}
