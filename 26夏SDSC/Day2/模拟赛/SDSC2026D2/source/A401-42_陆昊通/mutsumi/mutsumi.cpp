#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=1e6+5,mod=998244353,INF=0x3f3f3f3f3f3f3f3f;
ll n,m,k,ans,T;
ll b[20][20],a[N];
void dfs(ll x){
	ans=max(ans,x-1);
//	if(x==5){
//		cout<<x<<'\n';
//		for(int i=0;i<x;i++){
//			for(int j=1;j<=n-(i*2);j++) cout<<b[i][j]<<" ";
//			cout<<endl;
//		}
//		
//	}
	if(x*2>n)return;
	for(int i=1;i<n-(x-1)*2;i++){
		if(b[x-1][i]==i){
			for(int j=1;j<i;j++) b[x][j]=b[x-1][j];
			for(int j=i+2;j<=n-(x-1)*2;j++) b[x][j-2]=b[x-1][j];
			dfs(x+1);
		}
	}
}
mt19937 rnd(time(0));
ll bb[N],wz[N];
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],bb[i]=a[i];
	if(n<=8){
		for(int i=1;i<=n;i++) b[0][i]=a[i];
		dfs(1);
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		ll bob=0;
		for(int j=n-(i-1)*2-1;j>=1;j--){
			if(a[j]==j){
				bob=j;break;
			}
		}
		if(!bob)break;
		ans=i;
		for(int j=bob+1;j<n-(i-1)*2;j++)swap(a[j],a[j+1]);
		for(int j=bob;j<n-(i-1)*2-1;j++)swap(a[j],a[j+1]);
	}
	ll cnt=0;
	for(int sk=1;sk<=100;sk++){
		for(int i=1;i<=n;i++) a[i]=bb[i];
		for(int i=1;i<=n;i++){
			ll bob=0;cnt=0;
			for(int j=n-(i-1)*2-1;j>=1;j--){
				if(a[j]==j){
					wz[++cnt]=j;
				}
			}
			if(!cnt)break;
			ans=max(ans,(ll)i);
			bob=rnd()%cnt+1;
			for(int j=bob+1;j<n-(i-1)*2;j++)swap(a[j],a[j+1]);
			for(int j=bob;j<n-(i-1)*2-1;j++)swap(a[j],a[j+1]);
		}
	}
	cout<<ans;
	return 0;
}

