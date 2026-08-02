#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mod=998244353,a[1000009];
int aa(int a,int b) {
	int x=1;
	while(b) {
		if(b&1) x=x*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return x;
}

signed main() {
    freopen("tomori.in","r",stdin);
    freopen("tomori.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	if(n==1) {
		cout<<a[1];
		return 0;
	}
	if(n==2) {
		cout<<((a[1]+a[2])%mod*aa(2,mod-2))%mod;
		return 0;
	}
	if(n==3) {
		int x1=(a[1]+a[2])%mod*aa(2,mod-2)%mod;
		int x2=(a[2]+a[3])%mod*aa(2,mod-2)%mod;
		int x3=(x1+a[3])%mod*aa(2,mod-2)%mod;
		int x4=(x2+a[1])%mod*aa(2,mod-2)%mod;
		cout<<(x3*aa(2,mod-2)%mod+x4*aa(2,mod-2)%mod)%mod;
		return 0;
	}
	return 0;
}

