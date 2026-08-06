#include<bits/stdc++.h>
using namespace std;
const long long mod=1145141;
long long T;
long long ans;
long long d,n,a;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=1;
		cin>>d>>n>>a;
		for(long long i=0;i<n;i++)
		{
			ans=ans*(a+i*d)%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
