#include<bits/stdc++.h>
using namespace std;
int T , t;
int n , k , m;
int b[2000005] , c[2000005];
bool check() {
	if(b[1] < 1 || b[m] > n) return 0;
	if((n - m) % 2 == 1) return 0;
	if(k == 1) return (n != m);
	return 1;
}
int main() {
	freopen("uika.in" , "r" , stdin);
	freopen("uika.out" , "w" , stdout); 
	cin >> T;
	while(T--) {
		cin >> n >> k >> m;
		for(int i = 0 ; i < m ; i++) cin >> b[i]; 
		if(check()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
