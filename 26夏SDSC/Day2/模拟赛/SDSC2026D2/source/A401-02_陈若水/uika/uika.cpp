#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN = 2e6+8;
int t,n,k,m,a[MAXN];
int main()
{
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>m;
		for(int i = 1;i <= m;i++)cin>>a[i];
		if((n-m)%(k-1) != 0)
		{
			cout<<"NO\n";
			continue;
		}
		bool flag = 1;
		for(int i = 1;i <= m;i++)
		{
			if(a[i]-i == 0||n-m-a[i]+i == 0)continue;
			if(abs(2*a[i]-2*i-(n-m))%(k-1) == 0){
				cout<<"YES\n",flag = 0;
				break;
			}
			if((a[i]-i)>k/2&&(n-m-a[i]+i)>k/2)
			{
				cout<<"YES\n",flag = 0;
				break;			
			}
		}
		if(!flag)continue;
		cout<<"NO\n";
	}
	return 0;
}
