#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ft first
#define sd second
using namespace std;
const ll N=2e6+5;
mt19937_64 rd(time(0));
ll n,a[N],sum,f[N],b[N];
void solve(){
	ll bo=0;
	for(int i=n-1;i>=1;i--){
		if(a[i]==i){
			for(int j=i;j<n-1;j++)a[j]=a[j+2];
			n-=2;bo=1;sum++;
			break;
		}
	}
	if(bo)solve();
}
int main(){
 	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    		cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>18){
		solve();cout<<sum;return 0;
	}
	for(int i=1;i<(1<<n);i++){
		ll tot=0;f[i]=0;
		for(int j=0;j<n;j++)
			if((i>>j)&1)b[++tot]=j+1; 
		for(int j=1;j<tot;j++){
			if(a[b[j]]==j){
				f[i]=max(f[i],f[i^(1<<(b[j]-1))^(1<<(b[j+1]-1))]+1);
			}
		}
	}
	cout<<f[(1<<n)-1]<<endl;

    return 0;
}

