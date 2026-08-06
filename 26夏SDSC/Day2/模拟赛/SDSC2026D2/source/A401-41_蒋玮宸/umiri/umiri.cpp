#include<bits/stdc++.h>
#define int long long
#define lc (p<<1)
#define rc (p<<1|1)
using namespace std;
const int N=1e5+5;
struct Tree{
	int l,r,mn;
}tr[N<<2];
int n,m,w[N];
void build(int p,int l,int r){
	tr[p]={l,r,0};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	tr[p].mn=min(tr[lc].mn,tr[rc].mn);
}
void update(int p,int x,int k){
	if(tr[p].l==tr[p].r){
		tr[p].mn+=k;
		return ;
	}
	int mid=tr[p].l+tr[p].r>>1;
	if(x<=mid) update(lc,x,k);
	else update(rc,x,k);
	tr[p].mn=min(tr[lc].mn,tr[rc].mn);
}
int qmin(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y){
		return tr[p].mn;
	}
	int mid=tr[p].l+tr[p].r>>1,minn=9e18;
	if(x<=mid) minn=min(minn,qmin(lc,x,y));
	if(y>mid) minn=min(minn,qmin(rc,x,y));
	return minn;
}
signed main(){
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		int t=b;
		while(t--){
			int minn=qmin(1,1,a);
			int l=1,r=a;
			while(l<r){
				int mid=l+r>>1;
				if(w[mid]>minn) l=mid+1;
				else r=mid;
			}
			w[l]++;
			update(1,l,1);
		}
//		for(int i=1;i<=n;i++){
//			cout<<w[i]<<' ';
//		}cout<<'\n';
	}
	for(int i=1;i<=n;i++){
		cout<<w[i]<<'\n';
	}
	return 0;
}
