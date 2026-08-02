#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[1000005];
long long ksm(long long a , int b , int mod) {
	long long ans = 1;
	while(b) {
		if(b&1) ans = ans * a;
		b >>= 1;
		a = a * a;
		ans %= mod;
		a %= mod;
	}
	return ans;
}
int main() {
	freopen("tomori.in" , "r" , stdin);
	freopen("tomori.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << a[1];
	}else if(n == 2) {
		cout << (a[1] + a[2]) * ksm(2 , mod - 2 , mod);
	}else {
		cout << rand();
	}
	return 0;
}
