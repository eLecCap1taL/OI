#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+2;
int k,q,op,t,v,sn;
int l[max_n];
long long sum,ans;
map<int,deque<int> > s;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
void solve(){
	sum=0,ans=0;
	for(int i=1;i<=k;i++){
		if(s[i].empty()){
			continue;
		}
		pq.push({s[i][l[i]],i});
		l[i]++; 
	}
	while(!pq.empty()){
		auto p=pq.top();
		pq.pop();
		int now=p.first,id=p.second;
		sum+=now;
		ans+=sum;
		if(l[id]==s[id].size()){
			continue;
		}
		pq.push({s[id][l[id]],id});
		l[id]++;
	}
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("taki.in","r",stdin);
	freopen("taki.out","w",stdout);
	k=read(),q=read();
	for(int i=1;i<=k;i++){
		sn=read();
		for(int j=1;j<=sn;j++){
			int x=read();
			s[i].push_back(x);
		}
	}
	solve();
	printf("%lld\n",ans);
	for(int z=1;z<=q;z++){
		op=read(),t=read(),v=read();
		for(int i=1;i<=k;i++){
			l[i]=0;
		}
		if(op==0){
			s[t].push_front(v);
		}
		else{
			s[t].push_back(v);
		}
		solve();
		printf("%lld\n",ans);
	}
	return 0;
}
