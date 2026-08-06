#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

int n,m;
const int maxn = 1e5+ 10;
pii tr[maxn <<2];
int tag[maxn <<2];

#define lson (rt << 1)
#define rson (rt <<1 |1)
#define mid ((l+ r) >> 1)

void pushup(int rt){tr[rt] = min(tr[lson],tr[rson]);}
void build(int rt,int l,int r)
{
	tr[rt] = {0,l};
	if(l==r)return;
	build(lson,l,mid);
	build(rson,mid + 1,r); 
}
void pushdown(int rt)
{
	if(!tag[rt]) return;
	tr[lson].fi += tag[rt];
	tr[rson].fi += tag[rt];
	tag[lson] +=tag[rt];
	tag[rson]+=tag[rt];
	tag[rt]=0;
}
void update(int rt,int l,int r,int x,int y,int k)
{
	if(x >y)return;
	if(x<=l&& r <=y)
	{
		tr[rt].fi +=k;
		tag[rt] +=k;
		return;
	}
	pushdown(rt);
	if(x <=mid)update(lson,l,mid,x,y,k);
	if(y >mid)update(rson,mid + 1,r,x,y,k);
	pushup(rt);
}
pii query(int rt,int l,int r,int x,int y)
{
//	cout <<rt<<" ";
	if(x<=l&&r <=y)return tr[rt];
	pushdown(rt);
	pii ls,rs;
	int cnt =0;
	if(x<= mid) ls = query(lson,l,mid,x,y),cnt++;
	if(y > mid)rs = query(rson,mid +1,r,x,y),cnt +=2;
	if(cnt == 1)return ls;
	if(cnt ==2) return rs;
	return min(ls,rs);
}

signed main()
{
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>> n >> m;
	build(1,1,n);
	for(int i = 1;i <= m;i++)
	{
		int a,b;cin>>a >> b;
		while(b)
		{
			auto it = query(1,1,n,1,a);
//			cout << "fuck!!!"
			if(it.se != 1)
			{
//				cout << "ininin2";
				if(a - it.se + 1<= b)
				{
					b -= (a - it.se +1);
					update(1,1,n,it.se,a,1);
				}
				else 
				{
					update(1,1,n,it.se,it.se +b - 1,1);
					b = 0;
				}
			}
			else
			{
//				cout <<111 <<" ";
				update(1,1,n,1,a,b/a);
				update(1,1,n,1,b%a,1);
				b = 0;
			}
		}
	}	
	for(int i = 1;i <= n;i++) cout <<query(1,1,n,i,i).fi << '\n';
	return 0;
}



