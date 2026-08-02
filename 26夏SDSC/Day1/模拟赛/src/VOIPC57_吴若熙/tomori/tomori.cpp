#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ft first
#define sd second
using namespace std;
const ll N=2005,mod=998244353;
mt19937_64 rd(time(0));
ll n,g[N],f[205][205][205],a[N],inv[N],C[N][N];
ll poww(ll aa,ll b){
	ll hui=1;
	for(;b;b>>=1,aa=aa*aa%mod)if(b&1)hui=hui*aa%mod;
	return hui;
}
int main(){
 	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[1][1][0]=1;g[1]=1;g[2]=1;
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}	
	for(int i=3;i<=n;i++){
		for(int p=1;p<i;p++)g[i]+=g[p]*g[i-p]%mod*C[i-2][p-1],g[i]%=mod;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int p=1;p<i;p++){
				if(j>i/2+1){
					f[i][j][p]=f[i][i-j+1][p];
				}
				else{
					for(int z=j;z<i;z++){
						f[i][j][p]+=f[z][j][p-1]*g[i-z]%mod*C[i-2][z-1];
						f[i][j][p]%=mod;
					}
					for(int z=1;z<j;z++){
						f[i][j][p]+=g[z]*f[i-z][j-z][p-1]%mod*C[i-2][z-1];
						f[i][j][p]%=mod;
					}
				}
			}
		}
	}
	ll ans=0;inv[1]=poww(2,mod-2);
	for(int i=2;i<=n;i++)inv[i]=inv[i-1]*inv[1],inv[i]%=mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			ans+=a[i]*f[n][i][j]%mod*inv[j]%mod;ans%=mod;
		}
	}
	ans*=poww(g[n],mod-2);ans%=mod;
	cout<<ans;
    return 0;
}

