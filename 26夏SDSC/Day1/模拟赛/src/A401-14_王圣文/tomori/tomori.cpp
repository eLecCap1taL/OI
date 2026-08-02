#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int n;
const int xx=15;
int a[xx];
int main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n==1){
		cout<<a[1]<<"\n";
	}else if(n==2){
		cout<<(a[2]+a[1])/2*0.5<<"\n";
	}else if(n==3){
		cout<<((a[2]+a[1])/2+((a[2]+a[1])/2+a[3])/2)*0.5+((a[2]+a[3])/2+((a[2]+a[1])/2+a[1])/2)*0.5<<"\n";
	}
	return 0;
} 
