#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+2,mod=998244353;
int n,a[max_n];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n==1){
		puts("1");
	}
	else if(n==2){
		int fz=a[1]+a[2],fm=2;
		int g=__gcd(fz,fm);
		fz/=g,fm/=g;
		fz%=mod;
		for(int x=0;x<mod;x++){
			if((1ll*fm*x)%mod==fz){
				printf("%d\n",x);
				break;
			}
		}
	}
	else{
		puts("1");
	}
	return 0;
}
