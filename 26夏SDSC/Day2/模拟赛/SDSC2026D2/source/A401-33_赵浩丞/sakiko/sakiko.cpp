#include<bits/stdc++.h>
using namespace std;
const int mod=1145141;
int ksm(int a,int b){
	int res=1;
	while(b>0){
		if(b&1){
			res=(1ll*res*a)%mod;
//			res%=mod;
		} 
		a=(1ll*a*a)%mod;
		b>>=1;
	}
	return res%mod;
}
int v[1145150];
int jc[1145150<<1];
void init(){
	v[1]=1;
	for(int i=2;i<=mod;i++){
		int m=mod/i;
		int n=mod%i;
		v[i]=((1ll*(-m)*v[n]+mod)%mod+mod)%mod;
	}
}
signed main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	init();
	int T;
	cin>>T;
	jc[1]=jc[0]=1;
	for(int i=2;i<=(mod<<1);i++){
		jc[i]=(1ll*jc[i-1]*i)%mod;jc[i]%=mod; 
	}
	while(T--){
		int d,n,a;
		cin>>d>>n>>a;
		int ans=1;
		if(n>=mod){
			cout<<0<<'\n';
			continue;
		}
		if(d==0){
			cout<<ksm(a,n)<<'\n';
			continue;
		}
		if(n<=1000){
			while(n--){
				ans*=a;
				ans%=mod;
				a+=d;a%=mod;
			}
			cout<<ans<<'\n';
			continue;
		}else{
			int xx=ksm(d,n);
			int x_=(a*v[d])%mod;
			int yy=(1ll*jc[x_+n-1]*v[jc[x_-1]])%mod;
			cout<<(1ll*xx*yy)%mod<<'\n';
		}
	}
	return 0;
}
