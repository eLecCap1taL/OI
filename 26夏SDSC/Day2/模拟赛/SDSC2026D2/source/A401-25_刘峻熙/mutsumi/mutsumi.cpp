#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[15];
void dfs(int x,int res)
{
	ans=max(ans,res);
	vector<int> vec;
	vec.clear();
	vec.push_back(0);
	for(int i=1;i<=x;i++) vec.push_back(a[i]);
	for(int i=1;i<x;i++)
	{
		if(vec[i]==i)
		{
			int cnt=0;
			for(int j=1;j<=x;j++)
			{
				if(j==i or j==i+1) continue;
				a[++cnt]=vec[j];
			}
			dfs(cnt,res+1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(n,0);
	cout<<ans;
	return 0;
}
