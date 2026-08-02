#include<bits/stdc++.h>
#include<queue>
#define endl "\n"
#define ll long long
#define ft first
#define sd second
// #define int long long
#define db long double
#define pb push_back
#define mp make_pair
#define pe(j) (1ll<<(j))
#define foe(n) for(int i=1;i<=n;i++)
using namespace std;
inline void write(ll x);
inline ll read();
//bool stt;
const ll N=1e6+5,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
ll n,T,ans,m,k;
vector<ll> a[N],g[N];
ll le[N],zz[N];
priority_queue<pair<ll,ll> > q;
struct dat{
	ll x,id,wz;
	bool operator<(const dat &s)const{
		if(id==s.id) return wz<s.wz;
		return x<s.x;
	}
}b[N];
ll cnt;
//bool ed;
// cerr<<((&stt)-(&ed))/1024/1024.0<<endl;
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("taki.in","r",stdin);
	freopen("taki.out","w",stdout);
	cin>>k>>T;
	for(int i=1;i<=k;i++){
		a[i].pb(0);
		cin>>le[i];
		for(int j=1,su;j<=le[i];j++){
			cin>>su;
			b[++cnt]={su,i,j};
			a[i].pb(su);
		}
	}
	for(int i=1;i<=k;i++){
		if(!le[i]) {zz[i]=0;continue;}
		q.push(mp(-a[i][1],i));
		zz[i]=1;
	}
	ans=0;ll su=0;
//	sort(b+1,b+1+cnt);
//	for(int i=1;i<=cnt;i++) su+=b[i].x,ans+=su;
	while(!q.empty()){
		auto x=q.top();q.pop();
		su+=a[x.sd][zz[x.sd]];
		ans+=su;
		if(zz[x.sd]<le[x.sd]) zz[x.sd]++,q.push(mp(-a[x.sd][zz[x.sd]],x.sd));
	}
	cout<<ans<<endl;
	while(T--){
		ll op,t,v;
		cin>>op>>t>>v;
		a[t].pb(v);le[t]++;
		if(!op){
			for(int i=le[t]-1;i>=1;i--) swap(a[t][i],a[t][i+1]);
		} 
		for(int i=1;i<=k;i++){
			if(!le[i]) {zz[i]=0;continue;}
			q.push(mp(-a[i][1],i));
			zz[i]=1;
		}
		ans=0;ll su=0;
	//	sort(b+1,b+1+cnt);
	//	for(int i=1;i<=cnt;i++) su+=b[i].x,ans+=su;
		while(!q.empty()){
			auto x=q.top();q.pop();
			su+=a[x.sd][zz[x.sd]];
			ans+=su;
			if(zz[x.sd]<le[x.sd]) zz[x.sd]++,q.push(mp(-a[x.sd][zz[x.sd]],x.sd));
		}
		cout<<ans<<endl;
	}
	return 0;
}
//------------------------------------------------------------------------------------------
//read&write
inline ll read(){
    ll x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
    return x*w;
}
inline void write(ll x){
  static ll sta[35];
  ll top=0;
  do{sta[top++] = x % 10, x /= 10;}while (x);
  while(top) putchar(sta[--top]+48);
}

