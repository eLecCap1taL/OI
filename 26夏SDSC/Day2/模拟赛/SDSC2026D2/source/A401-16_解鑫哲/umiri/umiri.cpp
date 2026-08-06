#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 100005;
int n,m,pos[N];
ll sum[N*4],minn[N*4];
inline void pushup(int p){
	sum[p] = sum[p*2]+sum[p*2+1];
	minn[p] = min(minn[p*2],minn[p*2+1]);
}
void build(int l,int r,int p){
	if(l == r){
		sum[p] = 0;
		minn[p] = 0;
		pos[l] = p;
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	pushup(p);
}
ll get(int l,int r,int x,int y,int p){
	if(x > y)	return -1;
	if(l >= x && r <= y){
		return minn[p];
	}
	int mid = (l+r)>>1;
	ll res = -1;
//	printf("mid[%d,%d,%d](%d,%d)\n",l,mid,r,x,y);
	if(mid >= x)
		res = get(l,mid,x,y,p*2);
	if(mid < y){
		if(res == -1)	res = get(mid+1,r,x,y,p*2+1);
		else	res = min(res,get(mid+1,r,x,y,p*2+1));
	}
	return res;
}
void add(int l,int r,int x,int y,int p){
	if(l == r){
		sum[p]++;minn[p]++;
		return;
	}
	int mid = (l+r)>>1;
	if(l < x || r > y){
//		printf("add%d\n",mid);
		int lm = get(l,mid,x,mid,p*2);
		int rm = get(mid+1,r,mid+1,y,p*2+1);
		if((lm != -1 && lm <= rm) || rm == -1)	add(l,mid,x,y,p*2);
		else	add(mid+1,r,x,y,p*2+1);
	}
	else{
		if(minn[p*2] <= minn[p*2+1])
			add(l,mid,x,y,p*2);
		else
			add(mid+1,r,x,y,p*2+1);
	}
	pushup(p);
}
int main(){
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i = 1;i <= m;i++){
		int a;
		ll b;
		scanf("%d%lld",&a,&b);
		while(b--){
			add(1,n,1,a,1);
		}
	}
	for(int i = 1;i <= n;i++){
		printf("%lld\n",sum[pos[i]]);
	}
	return 0;
}
