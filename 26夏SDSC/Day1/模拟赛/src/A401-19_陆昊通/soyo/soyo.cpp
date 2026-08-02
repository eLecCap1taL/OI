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
vector<pair<ll,ll> > e[N];
ll f[N][2]; 
ll g[N][2],cnt;
ll b[N];
void dfs(ll x,ll la,ll bq){
	sort(e[x].begin(),e[x].end());
	for(auto i:e[x]){
		if(i.sd==la)continue;
		dfs(i.sd,x,i.ft);
	}
	cnt=0;
	
	for(auto i:e[x]){
		if(i.sd==la)continue;
		cnt++;
		b[cnt]=i.ft;
		g[cnt][0]=f[i.sd][0];
		g[cnt][1]=f[i.sd][1];
	}
	g[0][1]=1;
	g[cnt+1][0]=1;
	for(int i=1;i<=cnt;i++) g[i][1]=g[i-1][1]*g[i][1]%mod;
	for(int i=cnt;i>=1;i--) g[i][0]=g[i+1][0]*g[i][0]%mod;
	ll wz=lower_bound(b+1,b+1+cnt,bq)-b;
	wz=max(wz,1ll);
	for(int i=wz;i<=cnt+1;i++) f[x][0]+=g[i-1][1]*g[i][0]%mod,f[x][0]%=mod;
	 for(int i=0;i<=wz-1;i++) f[x][1]+=g[i][1]*g[i+1][0]%mod,f[x][1]%=mod;
//	cout<<x<<" "<<f[x][0]<<' '<<f[x][1]<<" "<<wz<<" "<<cnt<<endl; 
}
//bool ed;
// cerr<<((&stt)-(&ed))/1024/1024.0<<endl;
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("soyo.in","r",stdin);
//	freopen("rand.in","r",stdin);
	freopen("soyo.out","w",stdout);
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].pb(mp(i,v)),e[v].pb(mp(i,u));
	}
	dfs(1,0,INF);
	cout<<f[1][1];
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

