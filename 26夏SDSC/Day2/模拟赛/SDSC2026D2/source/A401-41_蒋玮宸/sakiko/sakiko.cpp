#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1145141ll;
int T,d,n,a,tot;
int ef(int l,int r){
	if(r-l+1==3){
		int mid=(l+r)>>1;
		tot++;
		return mid*(mid+1)*(mid-1);
	}
	int mid=(l+r)>>1;
	if(mid&1){
		return ef(l,mid)*ef(mid,r)/mid;
	}
	else{
		return ef(l,mid-1)*mid*ef(mid+1,r);
	}
}
void solve(){
	int ed=a+d*(n-1);
	int res;
	if(ed&1) res=ef(1,ed);
	else res=ef(1,ed-1)*ed;
	cout<<res<<'\n';
//	cout<<tot<<'\n';
}
void solve1(){
	int res=1ll%mod;
	for(int i=0;i<=n-1;i++){
		res=res*(a+i*d)%mod;
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>d>>n>>a;
		if(n<=1e4) solve1();
		else solve();
	}
	return 0;
}
