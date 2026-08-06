#include<bits/stdc++.h>
using namespace std;
const int mod=1145141;
int t,d,n,a;
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
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	t=read();
	for(int z=1;z<=t;z++){
		d=read(),n=read(),a=read();
		long long ans=1,now=0;
		for(int i=0;i<n;i++){
			now=a+1ll*i*d;
			ans=(ans*now)%mod;
			if(!ans){
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
