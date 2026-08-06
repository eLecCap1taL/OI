#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ft first
#define sd second
using namespace std;
const ll N=4e5+5;
mt19937_64 rd(time(0));
ll n,t[N],he[N];
void down(ll p,ll l,ll r,ll x){
	t[p]=x;he[p]=x*(r-l+1);
}
void change(ll p,ll l,ll r,ll l1,ll r1,ll x){
	if(l>=l1&&r<=r1){
		down(p,l,r,x);
		return;
	}
	ll mid=(l+r)>>1;
	if(t[p]){
		down(p*2,l,mid,t[p]);
		down(p*2+1,mid+1,r,t[p]);
		t[p]=0;
	}
	if(l1<=mid)change(p*2,l,mid,l1,r1,x);
	if(r1>mid)change(p*2+1,mid+1,r,l1,r1,x);
	he[p]=he[p*2]+he[p*2+1];
}
ll ask(ll p,ll l,ll r,ll l1,ll r1){
	if(l>=l1&&r<=r1)return he[p];
	ll mid=(l+r)>>1;
	if(t[p]){
		down(p*2,l,mid,t[p]);
		down(p*2+1,mid+1,r,t[p]);
		t[p]=0;
	}ll hui=0;
	if(l1<=mid)hui=ask(p*2,l,mid,l1,r1);
	if(r1>mid)hui+=ask(p*2+1,mid+1,r,l1,r1);
	return hui;
}
int main(){
 	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	ll m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		ll x,b;
		cin>>x>>b;
		ll l=1,r=x,ans=x,sh,zhi;
		while(l<=r){
			ll mid=(l+r)>>1;
			ll top=ask(1,1,n,mid,mid);
			ll hu=top*(x-mid+1)-ask(1,1,n,mid,x);
			if(hu<=b)ans=mid,r=mid-1,sh=b-hu,zhi=top;
			else l=mid+1;
		}
		change(1,1,n,ans,x,zhi);
		b=sh;
		l=b/(x-ans+1)+zhi;b%=(x-ans+1);
		if(l!=zhi)change(1,1,n,ans,x,l);
		if(b)change(1,1,n,ans,ans+b-1,l+1);
	}
	for(int i=1;i<=n;i++)cout<<ask(1,1,n,i,i)<<endl;
    return 0;
}

