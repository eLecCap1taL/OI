#include<bits/stdc++.h>
#define ll long long
#define dd double
#define ull unsigned ll
#define LL __int128
#define siz(A) ((int)A.size())
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int mod=1145141,xx=5e5+5;
int ksm(int a,int b=mod-2)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
int jiec[2*mod+2];
char ED;
int main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	jiec[0]=1;
	for(int i=1;i<=mod+mod;i++)jiec[i]=1ll*jiec[i-1]*i%mod;
	int T=read();
	while(T--)
	{
		int D=read()%mod,N=read(),A=read()%mod;
		if(D==0)
		{
			cout<<ksm(A,N)<<"\n";
			continue;
		}
		if(N>mod)
		{
			puts("0");
			continue;
		}
		if(A==0)
		{
			puts("0");
			continue;
		}
		A=1ll*A*ksm(D)%mod;
		cout<<1ll*ksm(D,N)*jiec[A+N-1]%mod*ksm(jiec[A-1])%mod<<"\n";
	}
	pc('1',1);
	return 0;
}
