#include<bits/stdc++.h>
#define ll long long
#define u64 unsigned long long

using namespace std;
int n,sum,sa,sb;
struct node{
	int a,b,s;
}k[510];
bool cmp(node x,node y){
	return x.a<y.a;
}
bool cmp1(node x,node y){
	if(x.s!=y.s)return x.s>y.s;
	if(x.a!=y.a)return x.a<y.a;
	return x.b>y.b;
}
node xx[510],yy[510];
int xz[510],yz[510];
int lx,ly,mx,p[510];
void dfs(int x){
	if(x>n){
		lx=0,ly=0,mx=0,sa=0,sb=0;
		for(int i=1;i<=n;i++){
			if(p[i])xx[++lx]=k[i];
			else yy[++ly]=k[i];
		}
		sort(xx+1,xx+lx+1,cmp1);
		sort(yy+1,yy+ly+1,cmp1);
		for(int i=1;i<=lx;i++){
			mx=max(mx,sa+xx[i].s);
			sa+=xx[i].a;
		}
		for(int i=1;i<=ly;i++){
			mx=max(mx,sb+yy[i].s);
			sb+=yy[i].a;
		}
		sum=min(sum,mx);
		return ;
	}
	p[x]=0;
	dfs(x+1);
	p[x]=1;
	dfs(x+1);
	return ;
}
void dfs1(int x){
	if(x>n){
		lx=0,ly=0,mx=0,sb=0;
		for(int i=1;i<=n;i++){
			if(p[i])xz[++lx]=lx;
			else yz[++ly]=ly;
		}
		do{
			do{
				for(int i=1;i<=lx;i++){
					mx=max(mx,sb+k[xz[i]].s);
					sb+=k[xz[i]].a;
				}	
				sb=0;
				for(int i=1;i<=ly;i++){
					mx=max(mx,sb+k[yz[i]].s);
					sb+=k[yz[i]].a;
				}
				sum=min(sum,mx);
			}while(next_permutation(yz+1,yz+ly+1));
		}while(next_permutation(xz+1,xz+lx+1));
		return ;
	}
	p[x]=0;
	dfs(x+1);
	p[x]=1;
	dfs(x+1);
	return ;
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>n;
	int test=0;
	for(int i=1;i<=n;i++){
		cin>>k[i].a>>k[i].b;
		k[i].s=k[i].a+k[i].b;
		if(i>1){
			if(k[i].b!=k[i-1].b)test=1;
		}
	}	
	if(n<=5){
		sum=1e9;
		dfs1(1);
		cout<<sum;
	}else if(n<=20){
		sum=1e9;
		dfs(1);
		cout<<sum;
	}else{
		sort(k+1,k+n+1,cmp);
		for(int i=1;i<=n;i++)sum+=k[i].a;
		cout<<sum+k[n].b;
	}
	return 0;
}

