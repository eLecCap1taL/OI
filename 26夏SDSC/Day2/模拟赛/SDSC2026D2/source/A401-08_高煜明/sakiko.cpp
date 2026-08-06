#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int P=1145141;
int T,d,n,a;
int main(){
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	cin>>T;
	while(T--){
		ll ans=1;
		cin>>d>>n>>a;
		for(int i=0;i<n;i++){
			ans*=(a+i*d);
			ans%=P;
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
} 
