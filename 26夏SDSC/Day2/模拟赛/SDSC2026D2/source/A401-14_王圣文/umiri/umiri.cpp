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
int n,m;
struct node{
	int a,b;
}z[1000005];
int qwq[100005];
int main()
{
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		z[i].a=read(),z[i].b=read();
		qwq[i]=0;
	}
	int tot=1;
	for(int i=1;i<=m;i++){
		if(tot==n) tot=1;
		qwq[tot++]+=1;	
	}
	for(int i=1;i<=n;i++){
		cout<<qwq[i]<<"\n";
	}
	return 0;
}
