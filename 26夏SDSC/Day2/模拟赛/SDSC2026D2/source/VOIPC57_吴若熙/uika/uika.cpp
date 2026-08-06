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
ll n,k,m,bo[N];
int main(){
 	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	ll T;cin>>T;
	while(T--){
		cin>>n>>k>>m;
		for(int i=1;i<=n;i++)bo[i]=0;
		for(int i=1;i<=m;i++){
			ll x;cin>>x;bo[x]=1;
		}
		m=n-m;//ÐèÒªÉ¾m¸ö 
		k--;ll shu=0,sum=0;
		if(m%k){cout<<"NO"<<endl;continue;}
		for(int i=1;i<=n;i++){
			if(!bo[i])sum++;
			if(bo[i]){
				if(sum>=k/2&&(m-sum)>=k/2){
					cout<<"YES"<<endl;shu=1;break;
				}
			}
		}
		if(!shu)cout<<"NO"<<endl;
	}
    return 0;
}

