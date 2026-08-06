#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define debug(...) fprintf(stderr,"[Line:%d] ",__LINE__),fprintf(stderr,##__VA_ARGS__)
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define fread freopen("sakiko.in","r",stdin)
#define fprint freopen("sakiko.out","w",stdout)
const int mod=1145141;
ll fac[mod],invfac[mod];
ll ksm(ll a,ll b){
    ll res=1;
    a%=mod;
    for(;b;b>>=1){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
    }
    return res;
}
void solve(){
    fac[0]=1;
    rep(i,1,mod-1)
    fac[i]=fac[i-1]*i%mod;
    invfac[mod-1]=ksm(fac[mod-1],mod-2);
    per(i,mod-2,0)
    invfac[i]=invfac[i+1]*(i+1)%mod;
}
ll get(ll d,ll n,ll a){
//    debug("d=%lld n=%lld a=%lld\n",d,n,a);
    if(n>=mod)return 0;
    d%=mod,a%=mod;
    if(d==0)return ksm(a,n);
    ll x=ksm(d,mod-2);
    ll l=a*x%mod;
    ll r=l+n-1;
    ll part=0;
    if(l!=0&&r<mod)
    part=fac[r]*invfac[l-1]%mod;
    ll ans=ksm(d,n)*part%mod;
//    debug("ans = %lld\n",ans);
    return ans;
}
int main(){
	fread;
	fprint;
    solve();
    int T;
	cin>>T;
    while(T--){
        ll d,n,a;
        cin>>d>>n>>a;
        cout<<get(d,n,a)<<'\n';
    }
    return 0;
}
