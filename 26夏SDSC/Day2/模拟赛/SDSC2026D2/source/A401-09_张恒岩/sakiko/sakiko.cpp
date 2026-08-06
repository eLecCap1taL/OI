#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=1145141; 
int t;
ll n,d,a,cnt;
ll fct[P+10],inv[P+10];
ll qpow(ll x,ll y){
	ll sum=1;
	while(y){
		if(y&1)sum=sum*x%P;
		x=x*x%P;
		y>>=1;
	}
	return sum;
}
int main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	fct[0]=1;
	for(int i=1;i<P;i++)fct[i]=fct[i-1]*i%P;
	inv[P-1]=qpow(fct[P-1],P-2);
	for(int i=P-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%P;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&d,&n,&a);
		a%=P;d%=P;
		if(d==0){
			printf("%lld\n",qpow(a,n));
			continue;
		}
	//	printf("%lld\n",(P-a%P)*qpow(d%P,P-2)%P);
		if(n-1>=(P-a)*qpow(d,P-2)%P){
			printf("0\n");
			continue;
		}
//		printf("aaa");
		ll S=1;
		if(d==1){
			S=fct[a+n-1]*inv[a-1]%P;
			printf("%lld\n",S);
			continue;
		}
		for(int i=0;i<=n-1;i++)S=S*(a+1ll*i*d)%P;
		printf("%lld\n",S%P);
	}
	return 0;
}
