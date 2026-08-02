#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n;
long long x,y;
long long ans=1;
long long dp[300005][2];
vector<pair<long long,long long> > vec[300005];
void dfs(long long x,long long fa,long long fw)
{
	long long sum=1;
	dp[x][0]=1;
	dp[x][1]=1;
	for(long long i=0;i<(long long)vec[x].size();i++)
	{
		long long val=vec[x][i].first,now=vec[x][i].second;
		if(now==fa) continue;
		dfs(now,x,val);
		if(x==1)
		{
			ans=(ans*dp[now][1]+sum*dp[now][0])%mod;
			sum=sum*dp[now][0]%mod;
			continue;
		}
		if(fw<val)
		{
			dp[x][0]=dp[x][0]*dp[now][1]%mod;
			dp[x][1]=(dp[x][1]*dp[now][1]+sum*dp[now][0])%mod;
		}
		else
		{
			dp[x][0]=(dp[x][0]*dp[now][1]+sum*dp[now][0])%mod;
			dp[x][1]=sum*dp[now][0]%mod;
		}
		sum=sum*dp[now][0]%mod;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	cin>>n;
	for(long long i=1;i<n;i++)
	{
		cin>>x>>y;
		vec[x].push_back(make_pair(i,y));
		vec[y].push_back(make_pair(i,x));
	}
	for(long long i=1;i<=n;i++)
	{
		sort(vec[i].begin(),vec[i].end());
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
