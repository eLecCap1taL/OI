#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,m;
ll ans[N];
struct BIT{
	ll a[N];
	int lowbit(int x){return x&(-x);}
	void add(int x,ll k){
		for(;x<=n;x+=lowbit(x))a[x]+=k;
	}
	void add_range(int x,int y,ll k){
		add(x,k);add(y+1,-k);
	}
	ll sum(int x){
		if(x==0)return sum(1);
		ll res=0;
		for(;x;x-=lowbit(x))res+=a[x];
		return res;
	}
}bit;
int main(){
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	scanf("%d%d",&n,&m);
	ans[0]=1e18;
	memset(bit.a,0,sizeof(bit.a));
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		int pos=a;
		while(b){
			int L=1,R=a+1;pos=0;
			ll sa=bit.sum(a);
			while(L<=R){
				int mid=(L+R)>>1;
				if(bit.sum(mid)>sa)L=mid+1,pos=mid;
				else R=mid-1;
			}
			pos++;
			if(pos==1){
				ll d=b/(a-pos+1);
				b%=(a-pos+1);
				if(d){
					bit.add_range(pos,a,d);
				}
				if(1ll*pos+b-1<=a)bit.add_range(pos,pos+b-1,1),b=0;
				else bit.add_range(pos,a,1),b-=(a-pos+1);
			}
			else {
				ll d=b/(a-pos+1);
				d=min(d,bit.sum(pos-1)-bit.sum(pos));
				if(d){
					bit.add_range(pos,a,d);
					b-=d*(a-pos+1);
				}
				else {
					if(1ll*pos+b-1<=a)bit.add_range(pos,pos+b-1,1),b=0;
					else bit.add_range(pos,a,1),b-=(a-pos+1);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d\n",bit.sum(i));
	return 0;
}

