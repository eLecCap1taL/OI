#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const int MOD = 1145141;
int d,n,a;
LL ans;
int main()
{
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>d>>n>>a,ans = 1;
		for(int i = 0;i <= n-1;i++)ans = (1ll*ans*(1ll*a+1ll*i*d)%MOD)%MOD;
		cout<<ans<<"\n";
	}
	return 0;
}
