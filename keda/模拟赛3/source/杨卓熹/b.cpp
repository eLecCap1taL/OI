#include<iostream>
#include<cmath>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define wt(s) s=" "+s
#define debug(i) cerr<<"dick"<<i<<endl 
using namespace std;
const int maxn=105;
ll n,vis[maxn][maxn];
string ans="";
string f[maxn][maxn];
//f:ǰi��С����ѡj��������ֵ��� 
string s,t;
inline void fre()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>s>>t; 
	n=s.size();
	wt(s),wt(t);
	vis[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!vis[i-1][j]) continue;
			if((!vis[i][j])||f[i][j]<f[i-1][j])
			{
				vis[i][j]=1;
				f[i][j]=f[i-1][j]; 
			}
			if(j+1<=n)
			{
				string s1=f[i-1][j].substr(0,j),s2=f[i-1][j].substr(j);
				string s3=s1+s[i]+s2+t[i];
				if((!vis[i][j+1])||f[i][j+1]<s3)
				{
					vis[i][j+1]=1;
					f[i][j+1]=s3;
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(vis[n][i]) ans=max(ans,f[n][i]);
	}
	cout<<ans;
	return 0;
} 
