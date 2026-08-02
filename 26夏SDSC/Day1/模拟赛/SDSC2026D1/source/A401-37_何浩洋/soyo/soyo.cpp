#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
struct aa {
	int v,w;
};
vector<aa> a[300009];
int f[300009][2],mod=998244353;
signed main() {
    freopen("soyo.in","r",stdin);
    freopen("soyo.out","w",stdout);
	cin>>n;
	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
		a[u].push_back({v,i});
		a[v].push_back({u,i});
	}
	if(a[n].size()==n-1) {
		cout<<n;
		return 0;
	}
	f[1][0]=f[1][1]=1;
	for(int i=2; i<n; i++) {
		f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
		f[i][1]=f[i-1][0]%mod;
	}
	cout<<(f[n-1][1]+f[n-1][0])%mod;
	return 0;
}

