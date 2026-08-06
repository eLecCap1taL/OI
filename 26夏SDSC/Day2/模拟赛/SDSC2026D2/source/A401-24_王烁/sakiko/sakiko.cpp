#include<bits/stdc++.h>
#define int long long
#define P 1145141
using namespace std;
int qpow(int x,int p){
	int res=1;
	while(p){
		if(p&1)res=res*x%P;
		x=x*x%P;
		p>>=1;
	}
	return res;
} 
signed main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	int t=0;
	scanf("%lld",&t);
	while(t--){
		int d,n,a;
		scanf("%lld%lld%lld",&d,&n,&a);
		if(d%1145141==0){
			printf("%lld\n",qpow(a,n));
			continue;
		}
		int res=1;
		for(int i=0;i<=n-1;i++){
			res=res*(a+i*d%P)%P;
			if(!res)break;
		}
		printf("%lld\n",res);
	} 
	return 0;
}

