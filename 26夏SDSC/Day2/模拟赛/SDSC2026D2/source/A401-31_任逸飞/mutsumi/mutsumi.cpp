#include<bits/stdc++.h>
using namespace std;
const int max_n=808;
int n,a[max_n];
int add,st[max_n],top,ans,ans_;
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
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		st[++top]=a[i];
		if(top>=2&&st[top-1]+add==i-1){
			top-=2,add+=2;
			ans++;
		}
	}
	top=0;
	for(int i=n;i>=1;i--){
		st[++top]=a[i];
		if(top>=2&&st[top]==i){
			top-=2,add+=2;
			ans_++;
		}
	}
	printf("%d\n",max(ans,ans_));
	return 0;
}
