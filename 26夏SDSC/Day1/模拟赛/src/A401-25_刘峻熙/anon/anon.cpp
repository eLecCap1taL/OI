#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int vis[505];
int a[505][505];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int ans=0,num=0;
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=1;j<=n;j++)
		{
			while(i+ans<=n and j+ans<=n)
			{
				for(int k=i;k<i+ans;k++)
				{
					if(!vis[a[k][j+ans]]) num++;
					vis[a[k][j+ans]]++;
				}
				for(int k=j;k<j+ans;k++)
				{
					if(!vis[a[i+ans][k]]) num++;
					vis[a[i+ans][k]]++;
				}
				if(!vis[a[i+ans][j+ans]]) num++;
				vis[a[i+ans][j+ans]]++;
				if(num>m)
				{
					for(int k=i;k<i+ans;k++)
					{
						vis[a[k][j+ans]]--;
						if(!vis[a[k][j+ans]]) num--;
					}
					for(int k=j;k<j+ans;k++)
					{
						vis[a[i+ans][k]]--;
						if(!vis[a[i+ans][k]]) num--;
					}
					vis[a[i+ans][j+ans]]--;
					if(!vis[a[i+ans][j+ans]]) num--;
					break;
				}
				ans++;
			}
			cout<<ans<<" ";
			ans--;
			for(int k=i;k<i+ans;k++)
			{
				vis[a[k][j]]--;
				if(!vis[a[k][j]]) num--;
			}
			for(int k=j+ans;k>j;k--)
			{
				vis[a[i+ans][k]]--;
				if(!vis[a[i+ans][k]]) num--;
			}
			vis[a[i+ans][j]]--;
			if(!vis[a[i+ans][j]]) num--;
		}
		cout<<"\n";
	}
	return 0;
}
