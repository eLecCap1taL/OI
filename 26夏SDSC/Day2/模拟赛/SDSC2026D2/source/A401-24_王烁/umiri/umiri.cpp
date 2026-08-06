#include<bits/stdc++.h>
#define N 100010
#define int long long
#define pii pair<int,int>
#define fi first
#define se second 
using namespace std;
int n,m,bk[N];
int mn[N<<2],pos[N<<2],add[N<<2];
#define lc (x<<1)
#define rc ((x<<1)|1)
#define mid ((l+r)>>1)
void pushup(int x){
	if(mn[lc]<=mn[rc])mn[x]=mn[lc],pos[x]=pos[lc];
	else mn[x]=mn[rc],pos[x]=pos[rc];
}
void pushdown(int x,int l,int r){
	int v=add[x];add[x]=0;
	if(v){
		add[lc]+=v;add[rc]+=v;
		mn[lc]+=v;mn[rc]+=v;
	}
}
void build(int x,int l,int r){
	if(l==r){
		pos[x]=l;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int from,int to,int v){
	if(from<=l&&r<=to){
		add[x]+=v;
		mn[x]+=v;
		return;
	}
	pushdown(x,l,r);
	if(from<=mid)modify(lc,l,mid,from,to,v);
	if(to>mid)modify(rc,mid+1,r,from,to,v);
	pushup(x);
}
pii query(int x,int l,int r,int from,int to){
	if(from<=l&&r<=to)return make_pair(mn[x],pos[x]);
	pushdown(x,l,r);
	int res=-1,id=-1;
	if(from<=mid){
		pii tmp=query(lc,l,mid,from,to);
		if(id==-1||tmp.fi<res)res=tmp.fi,id=tmp.se;
	}
	if(to>mid){
		pii tmp=query(rc,mid+1,r,from,to);
		if(id==-1||tmp.fi<res)res=tmp.fi,id=tmp.se;
	}
	return make_pair(res,id);
}
signed main(){
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	build(1,1,n);
	while(m--){
		int a,b;
		scanf("%lld%lld",&a,&b);
		//br-354 br-365 br-412 br-471
		while(b){
			pii res=query(1,1,n,1,a);
			int pos=res.se,val=res.fi;
			int layer=b/(a-pos+1),aim;
			if(pos!=1)aim=query(1,1,n,pos-1,pos-1).fi-val;
			else aim=1e18;
			if(layer>=aim){
				b-=aim*(a-pos+1);
				modify(1,1,n,pos,a,aim);
			}else{
				b-=layer*(a-pos+1);
				modify(1,1,n,pos,a,layer);
				if(b)modify(1,1,n,pos,pos+b-1,1),b=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%lld\n",query(1,1,n,i,i).first);
	return 0;
}
