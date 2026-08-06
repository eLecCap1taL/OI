#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,d,a,mod=1145141;
int ab(int a,int b) {
	int x=1;
	while(b) {
		if(b&1) x=x*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return x;
}
signed main() {
    freopen("sakiko.in","r",stdin);
    freopen("sakiko.out","w",stdout);
	cin>>T;
	while(T--) {
		int ans=1;
		cin>>d>>n>>a;
		d%=mod,a%=mod;
		if(d==0)
			cout<<ab(a,n)<<endl;
		else {
			for(int i=1; i<=n; i++) {
				ans=ans*a%mod;
				a=(a+d)%mod;
				if(ans==0)
					break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

