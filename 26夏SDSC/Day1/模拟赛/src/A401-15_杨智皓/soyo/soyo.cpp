#include<bits/stdc++.h>
using namespace std;
int n;
long long ans[300005];

int main(){
	ans[0] = 1;
	freopen("soyo.in", "r", stdin);
	freopen("soyo.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
	}
	for (int i = 1; i <= n; i++)
		ans[i] = ans[i-1]*2 % 998244353;
	cout << ans[n-1];
} 
