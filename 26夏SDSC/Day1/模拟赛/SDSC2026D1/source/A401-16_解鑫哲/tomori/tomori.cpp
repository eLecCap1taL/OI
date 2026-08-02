#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
typedef pair<int,int> PII;
const int mod = 998244353;
const int N = 1000006;
const int Inv_2 = 0; 
int n;
ll a[N];
int main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	if(n == 1)
		printf("%lld",a[1]);
	if(n == 2){
		if((a[1]+a[2])%2 == 0)
			printf("%lld",(((a[1]+a[2])/2)%mod));
		else{
			printf("%lld",(((a[1]+a[2])%mod)*Inv_2)%mod);
		}
	}
	return 0;
}
