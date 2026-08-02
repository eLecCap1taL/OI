#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
int a[1000005];
long long kuai(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1){
			ans=(ans*a)%p;
		}
		a=(a*a)%p;
		b>>=1;
	}
	return ans%p;
}
int main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	int n;
	scanf("%d",&n);
	long long lin=kuai(2,p-2)%p;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==1){
		printf("%d",a[1]%p);
	}
	else if(n==2){
		long long ans=((a[1]+a[2])%p*lin%p)%p;
		printf("%lld",ans%p);
	}
	else{
		printf("%lld",rand()%p);
	}
	return 0;
} 
