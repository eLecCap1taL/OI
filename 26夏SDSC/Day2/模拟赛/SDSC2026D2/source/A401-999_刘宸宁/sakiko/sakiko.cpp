#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define pr putchar(10)
#define fi first
#define se second
#define pp putchar(' ')
#define pii pair<ll,ll>
#define tri tuple<ll,ll,ll>
#define gt(k,x) (get<k>(x))
#define pdi pair<double,ll>
#define mem(aa,bb) memset(aa,bb,sizeof(aa))
#define fo(a,i,b) for(ll i = (a) ; i <= (b) ; ++ i )
#define Fo(a,i,b) for(ll i = (a) ; i >= (b) ; -- i )
#define pb push_back
#define reg register
#define eb emplace_back
#define bct __builtin_popcount 
#define mk make_pair
#define IT iterator
#define all(x) x.begin(),x.end()
#define lbd lower_bound
#define ubd upper_bound
#define lowbit(x) ((x)&(-(x)))
#define gb(x,i) (((x)>>i)&1)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define deb(a...) [&](auto...b){char s[]=" , ,"#a;strtok(s,",");((cerr<<strtok(0,",")<<"="<<b<<"; "),...)<<endl;}(__LINE__,a)
//#pragma GCC optimize(2)
using namespace std;
bool ST;

typedef long long i64;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef __int128 i128;
typedef __uint128_t u128;
typedef double db;

// typedef int ll;
typedef long long ll;
// typedef __int128 ll;

// #define getchar getchar_unlocked
// #define putchar putchar_unlocked

const ll mod=1145141;
template <class T> inline bool ckmn(T &a,T b){return a>b?a=b,1:0;}
template <class T> inline bool ckmx(T &a,T b){return a<b?a=b,1:0;}
template <class T> inline void _A(T &x,T y){x=(x+y>=mod?x+y-mod:x+y);}
template <class T> inline void _M(T &x,T y){x=1ll*x*y%mod;}
template <class T> inline T A_(T x,T y){return (x+y>=mod?x+y-mod:x+y);}
template <class T> inline T M_(T x,T y){return 1ll*x*y%mod;}
template <class T> inline void read(T &s)
{
   s=0;reg int f=1;reg char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
   while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();s*=f;return;
}
template <class T> inline void wr(T x)
{
   if(x<0)putchar('-'),x=-x;int buf[21],top=0;while(x)buf[++top]=x%10,x/=10;
   if(!top)buf[++top]=0;while(top)putchar(buf[top--]^'0');return;
}
template <class T, class ...A> inline void read(T &x,A &...a){read(x);read(a...);}
template <class T, class ...A> inline bool ckmn(T &x,T y,A ...a){return ckmn(x,y)|ckmn(x,a...);}
template <class T, class ...A> inline bool ckmx(T &x,T y,A ...a){return ckmx(x,y)|ckmx(x,a...);}
template <class T, class ...A> inline void _A(T &x,T y,A ...a){_A(x,y),_A(x,a...);}
template <class T, class ...A> inline void _M(T &x,T y,A ...a){_M(x,y),_M(x,a...);}
template <class T, class ...A> inline T A_(T x,T y,A ...a){return A_(A_(x,y),a...);}
template <class T, class ...A> inline T M_(T x,T y,A ...a){return M_(M_(x,y),a...);}

const ll _N=2e6+5;ll Pre[_N],Inv[_N];
inline ll qpow(ll a,ll b){return !b?1ll:M_(1ll*qpow(M_(a,a),b>>1ll),((b&1ll)?a:1ll));}
inline ll C(ll n,ll m){return (n<m||n<0||m<0)?0ll:M_(Pre[n],Inv[m],Inv[n-m]);}
inline void InitC(ll n){Pre[0]=1;fo(1,i,n) Pre[i]=M_(Pre[i-1],i);Inv[n]=qpow(Pre[n],mod-2);Fo(n-1,i,1) Inv[i]=M_(Inv[i+1],(i+1));Inv[0]=1;}

const ll N=1e6+5,M=1e5+5;
ll d,n,a,T;
inline void solve()
{
    read(d,n,a);if(n>=mod) return wr(0),pr,void();
    d%=mod,a%=mod;if(d==0) return wr(qpow(a,n)),pr,void();
    ll x=M_(a,qpow(d,mod-2));if(x+n-1>=mod) return wr(0),pr,void();
    if(!x) return wr(0),pr,void();
    wr(M_(qpow(d,n),Pre[x+n-1],Inv[x-1])),pr;
}
bool ED;
signed main(){
    freopen("sakiko.in","r",stdin);
    freopen("sakiko.out","w",stdout);
    read(T),InitC(mod-1);while(T--) solve();

    cerr << "Time: " << (double)clock()/CLOCKS_PER_SEC << "s\n";
    cerr << "Memory: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB\n";
    return 0;
}