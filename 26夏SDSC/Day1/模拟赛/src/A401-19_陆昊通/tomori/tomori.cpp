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
bool stt;
const ll N=1e6+5,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
ll n,T,ans,m,k;
ll a[N];
ll power(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
	return ans;
}
ll f[210][210][210]; 
namespace sub1{
	ll ans,su;
	ll b[11][11];
	void dfs(ll x){
		if(x>=n){
			su+=b[x-1][1];
			su%=mod;ans++;
			return;
		}
		for(int i=1;i<n-x+1;i++){
			ll cnt=0;
			for(int j=1;j<i;j++){
				b[x][j]=b[x-1][j];
			}
			b[x][i]=(b[x-1][i]+b[x-1][i+1])%mod*power(2,mod-2)%mod;
			for(int j=i+2;j<=n-x+1;j++) b[x][j-1]=b[x-1][j];
			dfs(x+1);
		}
	}
	void sovle(){
		for(int i=1;i<=n;i++) b[0][i]=a[i];
		dfs(1); 
		cout<<su*power(ans,mod-2)%mod;
	}
}
bool ed;
signed main(){
// cerr<<((&stt)-(&ed))/1024/1024.0<<endl;
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
//	if(n==1){
//		cout<<a[1];return 0;
//	}
//	else if(n==2){
//		cout<<(a[2]+a[1])%mod*power(2,mod-2)%mod;
//		return 0;
//	}
//	else if(n==3){
//		cout<<(3*a[1]+a[2]*2+a[3]*3)%mod*power(8,mod-2)%mod;
//		return 0; 
//	}
	
	
	
	if(n<=10){sub1::sovle();return 0;} 
	
	
	
	for(int i=1;i<=n;i++) f[0][i][i]=a[i];
	
	
	
	for(int i=1;i<n;i++){
		for(int l=1;l<=n;l++){
			for(int r=l;r<=l+i;r++){
				f[i][l][r]=f[i-1][l][r]*power(n-i+1,mod-2)%mod*(n-i)%mod;
				for(int k=l;k<=min(l+i-1,r);k++ ){
					f[i][l][r]+=(f[i-1][l][k]+f[i-1][k+1][r])*power(n-i+1,mod-2)%mod*power(2,mod-2)%mod;
					f[i][l][r]%=mod;
				}
			}
		}
	}
	cout<<f[n-1][1][n];
//	cout<<ans;
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

