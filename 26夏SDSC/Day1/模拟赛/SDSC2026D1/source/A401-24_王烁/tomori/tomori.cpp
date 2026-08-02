#include<bits/stdc++.h>
#define N 1000010
#define P 998244353
#define int long long
using namespace std;
int n,a[N]; 
int qpow(int x,int p){
	int res=1;
	while(p){
		if(p&1)res=res*x%P;
		x=x*x%P;
		p>>=1;
	}
	return res;
}
int dfs(vector<int>e){
	int m=e.size();
	if(m==0)return 0;
	if(m==1)return e[0]%P;
	int res=0;
	for(int i=0;i<m-1;i++){
		vector<int>v;
		for(int j=0;j<i;j++)v.push_back(e[j]%P);
		v.push_back((e[i]+e[i+1])%P*qpow(2,P-2)%P);
		for(int j=i+2;j<m;j++)v.push_back(e[j]%P);
		res=(res+dfs(v))%P;
	}
	return res*qpow(m-1,P-2)%P;
}
signed main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	scanf("%lld",&n);
	vector<int>e;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),e.push_back(a[i]);
	printf("%lld",dfs(e));
	return 0;
}

