#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 1e5+8;
int n,m;
LL dif[MAXN],c[MAXN];
int main()
{
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	cin>>n>>m;
	for(int i = 1,a,b;i <= m;i++)
	{
		cin>>a>>b;
		while(b > 0)
		{
			for(int j = 1;j <= a&&b > 0;j++)
				if(c[j] == c[a])c[j]++,b--;
		}
	}
	for(int i = 1;i <= n;i++)cout<<c[i]<<"\n";
	return 0;
} 
