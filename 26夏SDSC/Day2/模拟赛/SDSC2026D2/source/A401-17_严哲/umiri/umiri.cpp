#include<bits/stdc++.h>
#define int long long
#define mkp make_pair
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e5+5;
int n,m,a[N],b[N];
namespace Subtask1{
	struct Segment{
		struct node{
			int l,r;
			pii dat;
		}t[N<<2];
		pii Min(pii x,pii y){
			if(x.first<y.first||(x.first==y.first&&x.second<y.second)) return x;
			return y;
		}
		void push_up(int p) {t[p].dat=Min(t[p<<1].dat,t[p<<1|1].dat);}
		void build(int p,int l,int r){
			t[p].l=l;t[p].r=r;
			if(l==r){t[p].dat=mkp(0ll,l);return;}
			int mid=(l+r)>>1;
			build(p<<1,l,mid);
			build(p<<1|1,mid+1,r);
			push_up(p);
		}
		pii ask(int p,int l,int r){
			if(l<=t[p].l&&t[p].r<=r){
				return t[p].dat;
			}int mid=(t[p].l+t[p].r)>>1;
			pii res=mkp(INF,INF);
			if(l<=mid) res=Min(res,ask(p<<1,l,r));
			if(r>mid) res=Min(res,ask(p<<1|1,l,r));
			return res;
		}
		void change(int p,int x,int v){
			if(t[p].l==t[p].r){
				t[p].dat.first+=v;
				return;
			}
			int mid=(t[p].l+t[p].r)>>1;
			if(x<=mid) change(p<<1,x,v);
			else change(p<<1|1,x,v);
			push_up(p);
		}
	}T;
	void solve(){
		T.build(1,1,n);
		for(int i=1;i<=m;i++){
			int pos=T.ask(1,1,a[i]).second;
			T.change(1,pos,1);
		}
		for(int i=1;i<=n;i++)
			cout<<T.ask(1,i,i).first<<'\n';
	}
};
namespace Subtask{
	int c[N];
	void solve(){
		c[0]=INF;
		for(int i=1;i<=m;i++){
			int now=0;
			for(int j=a[i];j>=0;j--){
				if(now!=c[j]){
					if(!j){
						int l=0,r=b[i]-1,M=0;
						while(l<=r){
							int mid=(l+r)>>1;
							if(a[i]*mid<=b[i]){
								M=mid;l=mid+1;
							}
							else r=mid-1;
						}
						b[i]-=M*a[i];
						for(int k=1;k<=a[i];k++) c[k]+=M;
						for(int k=1;k<=b[i];k++) c[k]++;b[i]=0;
						continue;
					}
					int d=c[j]-now;
					if((a[i]-j)*d<=b[i]){
						b[i]-=(a[i]-j)*d;
						for(int k=j+1;k<=a[i];k++)
							c[k]=c[j];
						now=c[j];
					}
					else{
						int l=0,r=d-1,M=0;
						while(l<=r){
							int mid=(l+r)>>1;
							if((a[i]-j)*mid<=b[i]){
								M=mid;
								l=mid+1;
							}
							else r=mid-1;
						}
						b[i]-=(a[i]-j)*M;
						for(int k=j+1;k<=a[i];k++) c[k]+=M;
						for(int k=j+1;k<=j+b[i];k++) c[k]++;b[i]=0;
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++) cout<<c[i]<<'\n';
	}
};
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
		if(b[i]!=1)
			flag=1;
	}
	if(!flag) {Subtask1::solve();return 0;}
	else {Subtask::solve();return 0;}
	return 0;
}
