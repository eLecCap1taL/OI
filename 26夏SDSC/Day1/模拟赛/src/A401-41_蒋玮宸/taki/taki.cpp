#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=3e5+5;
int k,q,s[N],id[N];
int ans,n,sum[N];
vector<vector<int> >v;
priority_queue< PII >pq;
signed main(){
	freopen("taki.in","r",stdin);
	freopen("taki.out","w",stdout);
	cin>>k>>q;
	v.resize(k+1);
	for(int i=1;i<=k;i++){
		cin>>s[i];
		for(int j=1,x;j<=s[i];j++){
			cin>>x; v[i].push_back(x);
		}
	}
	for(int i=1;i<=k;i++){
		pq.push({v[i][0],i});
	}
	while(pq.size()){
		int x=pq.top().first,i=pq.top().second;
		pq.pop();
		sum[++n]=sum[n-1]+x;
		if(++id[i]<s[i]) pq.push({v[i][id[i]],i});
	}
	for(int i=1;i<=n;i++){
		ans+=sum[i];
	}
	cout<<ans<<'\n';
	return 0;
}
