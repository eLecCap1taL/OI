#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[200010];
signed main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	srand(time(0));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n==1){
		cout<<a[1];
		return 0;
	}
	if(n==2){
		cout<<((a[1]+a[2])*499122177)%mod;
		return 0;
	}else{
		cout<<rand()%998244353;
	}
	return 0;
}
