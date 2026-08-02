#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+10,P=998244353;
int n,id[N],u[N],v[N],dp[N][2];
bool flag1=1,flag2=1;
int dfs(int c)
{
	if(c==n)return 1;
	int res=0;
	if(id[u[c]]&&id[v[c]])res=0;
	else if(id[u[c]])
	{
		id[u[c]]++;
		res=dfs(c+1);
		id[u[c]]--;
	}
	else if(id[v[c]])
	{
		id[v[c]]++;
		res=dfs(c+1);
		id[v[c]]--;
	}
	else 
	{
		id[u[c]]++;
		res=dfs(c+1);
		id[u[c]]--;
		id[v[c]]++;
		res+=dfs(c+1);
		id[v[c]]--;
	}
	return res;
}
signed main()
{
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u[i]>>v[i];
		if(u[i]>v[i])swap(u[i],v[i]);
		if(v[i]!=n)flag2=0;
		if(u[i]!=i||v[i]!=i+1)flag1=0;
	}
	if(flag2)
	{
		cout<<n;
		return 0;
	}
	if(flag1)
	{
		dp[0][0]=dp[0][1]=1;
		for(int i=1;i<n;i++)
		{
			dp[i][0]=dp[i-1][0]+dp[i-1][1];
			dp[i][1]=dp[i-1][0];
		}
		cout<<max(dp[n-1][0],dp[n-1][1]);
		return 0;
	}
	cout<<dfs(1);
	return 0;
}
