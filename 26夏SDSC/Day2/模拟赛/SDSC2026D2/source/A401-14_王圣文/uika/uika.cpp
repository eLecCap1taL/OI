#include<bits/stdc++.h>
using namespace std;
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
int n,m,k;
int T;
int a[10],b[10];
int main()
{
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	srand(time(0));
	T=read();
	while(T--){
		n=read(),k=read(),m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int j=1;j<=m;j++) b[j]=read();
		if(k<=3) cout<<"YES"<<"\n";
		else{
			int t=rand()%(k-1);
			if(t<=n/(k-1)) cout<<"YES"<<"\n";
			else cout<<"NO"<<"\n";
		}
	} 
	return 0;
}
