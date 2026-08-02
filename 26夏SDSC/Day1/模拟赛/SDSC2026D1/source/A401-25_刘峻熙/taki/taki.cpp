#include<bits/stdc++.h>
using namespace std;
long long k,q;
long long s,a;
long long sum;
long long ans;
long long op,t,v;
long long num[300005];
deque<long long> dq[300005];
vector<long long> vec[300005];
priority_queue<pair<long long,long long> > Q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("taki.in","r",stdin);
	freopen("taki.out","w",stdout);
	cin>>k>>q;
	for(long long i=1;i<=k;i++)
	{
		cin>>s;
		for(long long j=1;j<=s;j++)
		{
			cin>>a;
			dq[i].push_back(a);
		}
		sum+=s;
	}
	for(long long i=1;i<=k;i++)
	{
		vec[i].clear();
		while(!dq[i].empty())
		{
			vec[i].push_back(dq[i].front());
			dq[i].pop_front();
		}
		for(long long j=0;j<(long long)vec[i].size();j++)
		{
			dq[i].push_back(vec[i][j]);
		}
	}
	for(long long i=1;i<=k;i++)
	{
		if(!vec[i].empty()) Q.push(make_pair(-vec[i][num[i]],i));
	}
	for(long long i=1;i<=sum;i++)
	{
		long long tq=Q.top().second;Q.pop();
		ans+=(sum-i+1)*vec[tq][num[tq]];
		num[tq]++;
		if(num[tq]<(long long)vec[tq].size())
		{
			Q.push(make_pair(-vec[tq][num[tq]],tq));
		}
	}
	cout<<ans<<"\n";
	for(long long i=1;i<=q;i++)
	{
		sum++;
		cin>>op>>t>>v;
		if(op==1)
		{
			dq[t].push_back(v);
		}
		else
		{
			dq[t].push_front(v);
		}
		for(long long i=1;i<=k;i++)
		{
			vec[i].clear();
			while(!dq[i].empty())
			{
				vec[i].push_back(dq[i].front());
				dq[i].pop_front();
			}
			for(long long j=0;j<(long long)vec[i].size();j++)
			{
				dq[i].push_back(vec[i][j]);
			}
		}
		ans=0;
		for(long long i=1;i<=k;i++) num[i]=0;
		for(long long i=1;i<=k;i++)
		{
			if(!vec[i].empty()) Q.push(make_pair(-vec[i][num[i]],i));
		}
		for(long long i=1;i<=sum;i++)
		{
			long long tq=Q.top().second;Q.pop();
			ans+=(sum-i+1)*vec[tq][num[tq]];
			num[tq]++;
			if(num[tq]<(long long)vec[tq].size())
			{
				Q.push(make_pair(-vec[tq][num[tq]],tq));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
