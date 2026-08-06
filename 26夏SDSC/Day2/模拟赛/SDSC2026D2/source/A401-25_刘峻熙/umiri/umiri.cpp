#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long tot;
long long a,b;
long long tag[400005];
long long tree[400005];
long long ls(long long p){return 2*p;}
long long rs(long long p){return 2*p+1;}
void push_up(long long p)
{
	tree[p]=tree[ls(p)]+tree[rs(p)];
}
void addtag(long long p,long long pl,long long pr,long long val)
{
	tag[p]=val;
	tree[p]=(pr-pl+1)*val;
}
void push_down(long long p,long long pl,long long pr)
{
	if(tag[p])
	{
		long long mid=(pl+pr)>>1;
		addtag(ls(p),pl,mid,tag[p]);
		addtag(rs(p),mid+1,pr,tag[p]);
	}
	tag[p]=0;
}
void update(long long l,long long r,long long p,long long pl,long long pr,long long val)
{
	if(l<=pl and pr<=r)
	{
		addtag(p,pl,pr,val); 
		return; 
	}
	push_down(p,pl,pr);
	long long mid=(pl+pr)>>1;
	if(mid>=l) update(l,r,ls(p),pl,mid,val);
	if(mid<r) update(l,r,rs(p),mid+1,pr,val);
	push_up(p); 
}
long long query(long long l,long long r,long long p,long long pl,long long pr)
{
	if(l<=pl and pr<=r) return tree[p];
	push_down(p,pl,pr);
	long long mid=(pl+pr)>>1,res=0;
	if(mid>=l) res+=query(l,r,ls(p),pl,mid);
	if(mid<r) res+=query(l,r,rs(p),mid+1,pr);
	return res;
}
bool check(long long x,long long y,long long k)
{
	return query(x,x,1,1,n)*(y-x+1)-query(x,y,1,1,n)<=k;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m;i++)
	{
		cin>>a>>b;
		long long l=1,r=a,ans=a;
		while(l<=r)
		{
			long long mid=(l+r)>>1;
			if(check(mid,a,b)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		long long num=query(ans,ans,1,1,n);
		b-=num*(a-ans+1)-query(ans,a,1,1,n);
		num+=b/(a-ans+1);
		update(ans,a,1,1,n,num);
		b%=(a-ans+1);
		if(b) update(ans,ans+b-1,1,1,n,num+1);
	}
	for(long long i=1;i<=n;i++)
	{
		cout<<query(i,i,1,1,n)<<"\n";
	}
	return 0;
}
