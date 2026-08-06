#include<bits/stdc++.h>
using namespace std;
const int mod = 1145141;
int t;
long long d , n , a;
int main() {
	freopen("sakiko.in" , "r" , stdin);
	freopen("sakiko.out" , "w" , stdout);
	cin >> t;
	while(t--) {
		cin >> d >> n >> a;
		if(n <= 10000) {
			long long res = a , ans = 1;
			for(int i = 1 ; i <= n ; i++) {
				ans = (ans * res) % mod;
				res = (res + d) % mod;
			}
			cout << ans << "\n";
			continue;
		}else{
			cout << 0 << "\n";
		}
	}
	return 0;
} 
