#include<bits/stdc++.h>
#define int long long
#define mkp make_pair
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e6+5;
int n,k,m,b[N];
namespace Subtask1{
	void solve(){
		for(int i=1;i<=m;i++) cin>>b[i];
		if(m==n){
			for(int i=1;i<=n;i++){
				if(b[i]!=i){
					cout<<"NO\n";
					return;
				}
			}
			cout<<"YES\n";
			return;
		}
		if((n-m)%2!=0) {cout<<"NO\n";return;}
		if((n-m)/2==1){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						vector<int> vec;
						for(int l=1;l<j;l++) if(l!=i) vec.push_back(i);
						vec.push_back(i);int flag=0;
						for(int l=j+1;l<=n;l++) if(l!=k) vec.push_back(i);
						for(int l=1;l<=4;l++) if(vec[l-1]!=b[l]) flag=1;
						if(!flag){
							cout<<"YES\n";
							return;
						}
					}
				}
			}
			cout<<"NO\n";
			return;
		}
		if((n-m)/2==2){
			if(n==5){
				if(m==1&&(b[1]==3||b[1]==4||b[1]==2)) cout<<"YES\n";
				else cout<<"NO\n";
			}
			else{
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(i-1>=1&&n-j>=1&&n-i-1>=2&&j-1-1>=2){
							if(b[1]==i&&b[2]==j){
								cout<<"YES\n";
								return;
							}
						}
					}
				}
				cout<<"NO\n";
				return;
			}
		}
	}
};
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n>>k>>m;
		if(n<=6&&k==3) Subtask1::solve();
	}
	return 0;
}
