#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=3e6+5,mod=998244353,INF=0x3f3f3f3f3f3f3f3f;
ll n,m,k,ans,T;
ll bo[N];
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>m;
		for(int i=1;i<=n;i++) bo[i]=0;
		for(int i=1,x;i<=m;i++){
			cin>>x;
			bo[x]=1;
		}
		ll sum=0;
		if((n-m)%(k-1)!=0){cout<<"NO\n";continue;}
		ll bob=0;
		for(int i=1;i<=n;i++){
			if(!bo[i]) sum++;
			else{
				if(sum>=(k-1)/2&&(n-m-sum)>=(k-1)/2){
					bob=1;break;
				}
			}
		}
		if(bob) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

