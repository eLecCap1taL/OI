#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
const int mod = 1145141;
int T;
ll d,n,a;
int main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&d,&n,&a);
		a = a%mod;
		ll r = (mod-a);
		if(d!=0 && r%d==0 && r/d < n) {
			printf("0\n");
			continue;
		}
		ll num = a;
		ll ans = 1;
		for(int i = 1;i <= n;i++){
			ans = (ans*num)%mod;
			num = (num + d)%mod;
			if(ans == 0){
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
