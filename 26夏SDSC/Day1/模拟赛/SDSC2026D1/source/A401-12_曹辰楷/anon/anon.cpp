#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
bitset<N>ne[N][N],p[N][N];
int n,k,a[N][N],ans[N][N];
signed main()
{
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			for(int len=1;len<=min(i,j);len++)
			{
				ne[i][j].set(a[i][j-len+1]),
				ne[i][j].set(a[i-len+1][j]);
				p[i-len+1][j-len+1]|=ne[i][j];
				if(p[i-len+1][j-len+1].count()<=k)
					ans[i-len+1][j-len+1]=len;
			}
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}
