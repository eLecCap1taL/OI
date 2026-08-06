#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<iomanip>
#include<set>
#define ll long long
using namespace std;
const int mod=1145141;
ll t,n,d,a;
ll get_num(int k) {
	ll ret=0;
	ret=(k-1)*d+a;
	ret=ret%mod;
	return ret;
}
bool jump;
ll calc(int l,int r) {
	if(n>=mod) return 0ll;
	if(l>r) return 1ll;
	if(l==r) return get_num(l);
	int mid=(l+r)>>1;
	ll L=calc(l,mid);
	ll R=calc(mid+1,r);
	ll ret=L*R%mod;
	return ret;
}
int main() {
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>d>>n>>a;
		d=d%mod,a=a%mod;
		cout<<calc(1,n)%mod<<endl;
	}
	return 0;
}
