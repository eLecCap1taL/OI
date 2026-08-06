#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1145141;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c!=EOF&&'0'<=c&&c<='9') {
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
}
signed main() {
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	int T,sta,d,s;
	T=read();
	while(T--) {
		d=read(),s=read(),sta=read();
		sta%=MOD,d%=MOD;
		int ans=1;
		if(s<1145142)
			for(int i=0; i<s; i++) {
				(ans*=(sta+i*d%MOD))%=MOD;
				if(!ans) break;
			}
		else ans=0;
		cout<<ans<<"\n";
	}
	return 0;
}
