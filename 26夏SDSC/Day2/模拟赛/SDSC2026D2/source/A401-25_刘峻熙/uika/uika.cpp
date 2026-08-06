#include<bits/stdc++.h>
using namespace std;
int T;
int ans;
int n,K,m;
int a[15],b[15];
bool check()
{
	for(int i=1;i<=m;i++)
	{
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
void dfs(int x)
{
	if(x==m)
	{
		if(check()) ans=1;
		return;
	}
	vector<int> vec;
	vec.clear();
	vec.push_back(0);
	for(int i=1;i<=x;i++) vec.push_back(a[i]);
	for(int i=1;i<=x;i++)
	{
		for(int j=i+2;j<=x;j++)
		{
			int cnt=0;
			for(int k=1;k<=x;k++)
			{
				if(k==i or k==j) continue;
				a[++cnt]=vec[k];
			}
			dfs(cnt);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>K>>m;
		for(int i=1;i<=m;i++) cin>>b[i];
		if((n-m)%2==0)
		{
			for(int i=1;i<=n;i++) a[i]=i;
			dfs(n);
			if(ans) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}
