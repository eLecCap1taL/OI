#include<bits/stdc++.h>
#define mod 998244353
#define int long long
#define mkp make_pair
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int ksm(int a,int b){
	int now=1;
	for(;b;b>>=1,a=a*a%mod){
		if(b&1) now=now*a%mod;
	}
	return now;
}
const int N=205;
int n,a[N],inv2=ksm(2,mod-2);
int ans=0;
void dfs(int dep,int now,vector<int> &t){
	if(dep>n-1){
		ans=(ans+now*t[0]%mod)%mod;
		return;
	}
	vector<int> tt;
	for(int i=0;i<t.size()-1ll;i++){
		tt.push_back((t[i]+t[i+1])*inv2%mod);
		for(int j=i+2;j<t.size();j++) tt.push_back(t[j]);
		dfs(dep+1,now*ksm(t.size()-1,mod-2)%mod,tt);
		for(int j=i+2;j<t.size();j++) tt.pop_back();
		tt.pop_back();
		tt.push_back(t[i]);
	}
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	cin>>n;
	vector<int> vec;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vec.push_back(a[i]);
	}
	dfs(1,1,vec);
	cout<<ans;
	return 0;
}
