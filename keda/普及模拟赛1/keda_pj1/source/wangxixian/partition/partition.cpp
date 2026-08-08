#include<bits/stdc++.h>
#define ll long long
#define u64 unsigned long long

using namespace std;
const ll mod=998244353;
int n,a[210],p[210],b[210];
ll cnt;
int t[10];
void dfs(int x){
	if(x>n){
		int sum=0,ss=0;
		for(int i=1;i<=n;i++){
			if(p[i])sum|=a[i];
			else ss|=a[i];
		}
		if(sum==ss)cnt++;
		cnt%=mod;
		return ;
	}
	p[x]=0;
	dfs(x+1);
	p[x]=1;
	dfs(x+1);
	return ;
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(1);
	}else{
		for(int i=1;i<=n;i++)b[i]=a[i];
		memset(a,0,sizeof a);
		int tp=0;
		for(int i=1;i<=n;i++){
			if(t[b[i]]<2)a[++tp]=b[i];
			t[b[i]]++;
		}
		n=tp;
		dfs(1);
	}
	cout<<cnt;
	return 0;
}

