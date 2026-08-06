#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 808;
int n,a[MAXN],cnt,fnow,ans;
bool flag = 1;
int main()
{
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	cin>>n,cnt = n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	while(flag)
	{
		fnow = 0;
		for(int i = 1;i < cnt;i++)if(a[i] == i)fnow = i;
		if(!fnow)break;
		for(int i = fnow;i <= cnt-2;i++)a[i] = a[i+2];
		ans++,cnt -= 2;
	}
	cout<<ans;
	return 0;
}
