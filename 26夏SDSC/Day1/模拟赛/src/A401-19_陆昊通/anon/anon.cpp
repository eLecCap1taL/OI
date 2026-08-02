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
ll bo[N];
ll a[510][510],an[510][510];
//bool ed;
// cerr<<((&stt)-(&ed))/1024/1024.0<<endl;
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("anon.in","r",stdin);
//	freopen("rand.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	ll sum=0;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++) bo[i]=0;sum=0;
		ll r=1;
		bo[a[i][1]]++;sum++;
		for(int l=1;l<=n;l++){
			while(r<=n&&r-l+1<=n-i+1&&sum<=k){
//				cerr<<l<<" "<<r<<endl;
				r++;
				for(int j=i;j<=i+r-l;j++){
					if(!bo[a[j][r]]) sum++;
					bo[a[j][r]]++;
				}
				for(int j=l;j<r;j++){
					if(!bo[a[i+r-l][j]] ) sum++;
					bo[a[i+r-l][j]]++;
				}
			}
			
			an[i][l]=r-l;
			for(int j=i;j<=i+r-l;j++){
				bo[a[j][l]]--; 
				if(!bo[a[j][l]]) sum--;
			}
			for(int j=l+1;j<=r;j++){
				bo[a[i+r-l][j]]--;
				if(!bo[a[i+r-l][j]] ) sum--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<an[i][j]<<' ';
		}
		cout<<endl;
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

