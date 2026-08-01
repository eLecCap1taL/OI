#include<bits/stdc++.h>
namespace ifzw{
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
const int xx=1e5+5;
int n,q;
ll sum[xx<<2],mx[xx<<2],cvt[xx<<2];
int siz[xx<<2];
void build(int k,int l,int r)
{
	siz[k]=r-l+1;
	if(l==r)return ;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void cv(int k,ll z){sum[k]=siz[k]*z,mx[k]=z,cvt[k]=z;}
void pd(int k){if(cvt[k]!=-1)cv(k<<1,cvt[k]),cv(k<<1|1,cvt[k]),cvt[k]=-1;}
void cov(int k,int l,int r,int x,int y,ll z)
{
	if(x>y)return;
	if(x<=l&&r<=y)return cv(k,z);
	pd(k);int mid=l+r>>1;
	if(x<=mid)cov(k<<1,l,mid,x,y,z);
	if(mid<y)cov(k<<1|1,mid+1,r,x,y,z);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
ll Sa,Sb;
int bin(int k,int l,int r,int A)
{
	if(r<=A)
	{
		if((LL)mx[k]*(A-l+1)-Sa-sum[k]<=Sb)return Sa+=sum[k],l;
	}
	if(l==r)return r+1;
	pd(k);
	int mid=l+r>>1;
	if(A<=mid)return bin(k<<1,l,mid,A);
	int to=bin(k<<1|1,mid+1,r,A);
	if(to==mid+1)return bin(k<<1,l,mid,A);
	return to;
}
ll get(int k,int l,int r,int x)
{
	if(l==r)return mx[k];
	pd(k);int mid=l+r>>1;
	if(x<=mid)return get(k<<1,l,mid,x);
	return get(k<<1|1,mid+1,r,x);
}
void dw(int k,int l,int r)
{
	if(l==r)return cout<<sum[k]<<"\n",void();
	pd(k);int mid=l+r>>1;
	dw(k<<1,l,mid);
	dw(k<<1|1,mid+1,r);
}
char ED;
int main(){
	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	n=read(),q=read();
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		ll a=read(),b=read();
		Sa=0,Sb=b;
		int id=bin(1,1,n,a);
		ll nv=get(1,1,n,id);
		int sz=a-id+1;
		b-=(nv*sz-Sa);
		ll dlt=b/sz;
		cov(1,1,n,id,id+b-(dlt*sz)-1,nv+dlt+1);
		cov(1,1,n,id+b-(dlt*sz),a,nv+dlt);
	}
	dw(1,1,n);
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}
