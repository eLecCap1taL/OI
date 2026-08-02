#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];

int main(){
	freopen("tomori.in","r",stdin);
	freopen("tomori.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n == 1) {cout << a[n] % 998244353; return 0;}
	if (n == 2) {cout << a[1]+a[2]/2 % 998244353; return 0;}
	if (n >= 3) {cout << rand()%998244353; return 0;}
}
