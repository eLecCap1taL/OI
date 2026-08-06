#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,inf=1e12+10;
int n,q,a[N];
vector<pair<int,int> >d;
void solve()
{
	cin>>n>>q;
	if(n*q<=1000000)
	{
		a[0]=inf;
		for(int i=1;i<=q;i++)
		{
			int r,k;
			cin>>r>>k;
			int sum=0;
			for(int j=r;j>=1;j--)
			{
				sum+=a[j];
//				cout<<a[j]<<' ';
				int nd=a[j-1]*(r-j+1)-sum;
				if(nd>k)
				{
//					cout<<'\n';
					int nnd=a[j]*(r-j+1)-sum,nh=(k-nnd)/(r-j+1),tmp=a[j];
//					cout<<j<<' '<<r<<' '<<nnd<<' '<<nh<<'\n';
					for(int t=j;t<=j+(k-nnd)%(r-j+1)-1;t++)a[t]=tmp+nh+1;
					for(int t=j+(k-nnd)%(r-j+1);t<=r;t++)a[t]=tmp+nh;
					break;
				}
			}
//			for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//			cout<<'\n';
		}
		for(int i=1;i<=n;i++)cout<<a[i]<<'\n';
		return;
	}
	for(int i=1;i<=q;i++)
	{
		int r,k;cin>>r>>k;
		for(int j=1;j<=k;j++)
		{
			int minn=a[n-r+1],w=upper_bound(a+1,a+n+1,minn)-a-1;
			a[w]++;
		}
	}
	for(int i=n;i>=1;i--)cout<<a[i]<<'\n';
}
signed main()
{
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	int _T_=1;
//	cin>>_T_;
	while(_T_--)solve();
}
/*
10 10
10 10
9 20
8 30
7 40
6 50
5 60
4 70
3 80
2 90
1 100
*/
