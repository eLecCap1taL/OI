#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+10,P=998244353;
int n,a[N],dp[N][N],pre[N][N],suf[N][N];
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int inv(int a)
{
	return qpow(a,P-2); 
}
signed main()
{
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>dp[i][i],pre[i][i]=suf[i][i]=dp[i][i];
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i<=n;i++)
		{
			int j=i+len-1;
			dp[i][j]=(pre[i][j-1]+suf[j][i+1])%P;
			dp[i][j]=dp[i][j]*(inv(2))%P*inv(len-1)%P;
			pre[i][j]=(pre[i][j-1]+dp[i][j])%P;
			suf[j][i]=(suf[j][i+1]+dp[i][j])%P;
		}
	}
	cout<<dp[1][n];
	return 0;
}
