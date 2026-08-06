#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1145141+10,P=1145141;
int n,a[N],ans;
bitset<N>vis;
void dfs(int c,int cnt)
{
//	cout<<c<<' '<<cnt<<'\n';
	if(cnt>n/2)return;
	if(c==n)
	{
		if(cnt<ans)return;
		vector<int>num;
		for(int i=1;i<n;i++)if(vis[i])num.push_back(i);
		bool flag=0;
		do{
			bitset<N>did;
			bool ft=1;
			for(auto u:num)
			{
				int lst=0;
				for(int i=1;i<u;i++)if(did[i])lst++;
				int id=u-lst;
				if(id!=a[u]||did[u])
				{
					ft=0;
					break;
				}
				did[u]=1;
				for(int i=u+1;i<=n;i++)if(!did[i])
				{
					did[i]=1;
					break;
				}
			}
			if(ft)
			{
				flag=1;break;
			}
//			cout<<'\n';
		}while(next_permutation(num.begin(),num.end()));
		if(flag)ans=max(ans,cnt);
//		cout<<'\n';
		return;
	}
	dfs(c+1,cnt);
	if(a[c]<=c&&!((c-a[c])&1))
	{
//		cout<<"check";
		vis[c]=1;
		dfs(c+1,cnt+1);
		vis[c]=0;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	cout<<ans;
}
signed main()
{
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	int _T_=1;
//	cin>>_T_;
	while(_T_--)solve();
}

/*
5
1 3 1 5 5
*/
