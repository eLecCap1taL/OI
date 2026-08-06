#include<bits/stdc++.h>
using namespace std;
const long long p=1145141;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		freopen("sakiko.in","r",stdin);
		freopen("sakiko.out","w",stdout);
		long long d,n,a;
		scanf("%lld %lld %lld",&d,&n,&a);
		long long ans=a;
		long long shang=a;
		for(int i=1;i<n;i++){
			long long now=(shang+d)%p;
			ans=(ans*now)%p;
		}
		printf("%lld\n",ans%p);
	}
	return 0;
} 
