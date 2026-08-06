#include<bits/stdc++.h>
using namespace std;
const int N=55;
string a,b;
string f[N][N]={""},g[N][N]={""};
bool tag[N];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>a>>b;
	a="#"+a,b="#"+b;
	string ans="";
	for(int i=1;i<a.length();i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=0;k<i;k++)
			{
				if(f[k][j-1]+a[i]+g[k][j-1]+b[i]>f[i][j]+g[i][j]) f[i][j]=f[k][j-1]+a[i],g[i][j]=g[k][j-1]+b[i];
			}
			ans=max(ans,f[i][j]+g[i][j]);
		}
	}
	cout<<ans; 
}
