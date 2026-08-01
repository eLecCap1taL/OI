#include<bits/stdc++.h>
#define ll long long
#define dd double
#define ull unsigned ll
#define LL __int128
#define siz(A) ((int)A.size())
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
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
const int xx=1e6+5;
int q,k;
vector<int>lin[xx];
int sz[xx];
struct nod{int op,ti,val;}Q[xx];

ll nval;

struct info
{
	int sz;
	ll sum;
	bool operator <(const info&w)const{return /*sum/sz<w.sum/w.sz*/sum*w.sz==w.sum*sz?sz<w.sz:sum*w.sz<w.sum*sz;}
	info&operator +=(const info&w){sz+=w.sz,sum+=w.sum;return *this;}
}I[xx],tv[xx];

ll S[xx];

vector<info>v[xx];

int L[xx],R[xx],c[xx][2],cst,rt;
mt19937 G(218);
unsigned rd[xx];
void upd(int k)
{
	tv[k]=I[k],S[k]=0;
	if(c[k][0])S[k]+=S[c[k][0]]+tv[k].sz*tv[c[k][0]].sum,tv[k]+=tv[c[k][0]];
	if(c[k][1])S[k]+=S[c[k][1]]+tv[c[k][1]].sz*tv[k].sum,tv[k]+=tv[c[k][1]];
}
void split(int k,info A,int &x,int &y)//��ΪС�ںʹ��ڵ��ڡ� 
{
	if(!k)return x=y=0,void();
	if(I[k]<A)x=k,split(c[k][1],A,c[k][1],y);
	else y=k,split(c[k][0],A,x,c[k][0]); 
	upd(k);
}
void Split(int k,info A,int &x,int &y)//��ΪС�ڵ��ںʹ��ڡ� 
{
	if(!k)return x=y=0,void();
	if(A<I[k])y=k,Split(c[k][0],A,x,c[k][0]);
	else x=k,Split(c[k][1],A,c[k][1],y);
	upd(k);
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(rd[x]<rd[y])return c[x][1]=merge(c[x][1],y),upd(x),x;
	return c[y][0]=merge(x,c[y][0]),upd(y),y;
}
void era(info A)
{
	int x,y,z;
	split(rt,A,x,y);
	Split(y,A,y,z);
	y=merge(c[y][0],c[y][1]);
	rt=merge(x,merge(y,z));
}
void ins(info A)
{
	int x,y;
	split(rt,A,x,y);
	int p=++cst;
	I[p]=tv[p]=A,rd[p]=G();
	rt=merge(x,merge(p,y));
}
void fr(int ti,int val)
{
	v[ti][--L[ti]]={1,val};
	while(L[ti]<R[ti]&&!(v[ti][L[ti]]<v[ti][L[ti]+1]))
	{
		nval+=v[ti][L[ti]+1].sz*v[ti][L[ti]].sum;
		era(v[ti][L[ti]+1]);
		v[ti][L[ti]+1]+=v[ti][L[ti]],L[ti]++;
	}
	ins(v[ti][L[ti]]);
	
	nval+=val;
}
void bk(int ti,int val)
{
	v[ti][++R[ti]]={1,val};
	while(L[ti]<R[ti]&&!(v[ti][R[ti]-1]<v[ti][R[ti]]))
	{
		nval+=v[ti][R[ti]].sz*v[ti][R[ti]-1].sum;
		era(v[ti][R[ti]-1]);
		v[ti][R[ti]-1]+=v[ti][R[ti]],R[ti]--;
	}
	ins(v[ti][R[ti]]);
	
	nval+=val;
}
void print(){cout<<nval+S[rt]<<"\n";}
char ED;
int main(){
	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
	freopen("taki.in","r",stdin);
	freopen("taki.out","w",stdout);
	k=read(),q=read();
	for(int i=1;i<=k;i++)
	{
		sz[i]=read();
		lin[i].resize(sz[i]);
		for(auto &it:lin[i])it=read();
	}
	for(int i=1;i<=q;i++)
	{
		int op=read(),ti=read(),val=read();
		Q[i]={op,ti,val},sz[ti]++;
	}
	
	for(int i=1;i<=k;i++)
		v[i].resize(sz[i]*2+2),L[i]=sz[i],R[i]=L[i]-1;
	for(int i=1;i<=k;i++)
		for(auto it:lin[i])bk(i,it);
//	cerr<<nval<<"#\n";
	print();
	for(int i=1;i<=q;i++)
	{
		if(Q[i].op==0)fr(Q[i].ti,Q[i].val);
		else bk(Q[i].ti,Q[i].val);
		print();
	}
	
	
	pc('1',1);
	return 0;
}
