#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=1e5;
int d[N<<2],b[N<<2];
void ab(int l,int mid,int r,int p) {
	if(b[p]) {
		d[p*2]+=b[p]*(mid-l+1),b[p*2]+=b[p];
		d[p*2+1]+=b[p]*(r-mid),b[p*2+1]+=b[p];
		b[p]=0;
	}
}
void xg(int s,int t,int k,int l,int r,int p) {
	if(s<=l&&r<=t) {
		d[p]+=(r-l+1)*k,b[p]+=k;
		return ;
	}
	int mid=(l+r)/2;
	ab(l,mid,r,p);
	if(s<=mid) xg(s,t,k,l,mid,p*2);
	if(t>mid) xg(s,t,k,mid+1,r,p*2+1);
	d[p]=d[p*2]+d[p*2+1];
}
int cx(int s,int t,int l,int r,int p) {
	if(s<=l&&r<=t)
		return d[p];
	int mid=(l+r)/2,sum=0;
	ab(l,mid,r,p);
	if(s<=mid) sum+=cx(s,t,l,mid,p*2);
	if(t>mid) sum+=cx(s,t,mid+1,r,p*2+1);
	return sum;
}
void aa(int p,int e) {
	while(e) {
		int l=1,r=p;
		int h=cx(r,r,1,n,1),x;
		while(l<=r) {
			int mid=(l+r)/2;
			if(cx(mid,mid,1,n,1)==h) x=mid,r=mid-1;
			else l=mid+1;
		}
		if(x==1) {
			int y=e/p,z=e%p;
			if(z) xg(1,z,1,1,n,1);
			if(y!=0) xg(1,p,y,1,n,1);
			return ;
		}
		int y=e/(p-x+1),c=cx(x-1,x-1,1,n,1),z=e%(p-x+1);
		if(y>c-h)
			xg(x,p,c-h,1,n,1),e=e-(p-x+1)*(c-h);
		else {
			xg(x,p,y,1,n,1);
			if(z) xg(x,x+z-1,1,1,n,1);
			return ;
		}
	}
}
signed main() {
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int p,e;
		cin>>p>>e;
		aa(p,e);
	}
	for(int i=1; i<=n; i++)
		printf("%d\n",cx(i,i,1,n,1));
	return 0;
}

