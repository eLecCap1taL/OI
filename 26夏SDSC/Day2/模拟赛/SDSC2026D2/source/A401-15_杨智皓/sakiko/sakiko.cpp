#include<bits/stdc++.h>
using namespace std;
#define MOD 1145141

int main(){
	freopen("sakiko.in", "r", stdin);
	freopen("sakiko.out", "w", stdout);
	int T; cin >> T;
	while(T--){
		long long res = 1;
		int d, n, a; cin >> d >> n >> a;
		for (int i = 0; i < n; i++){
			res *= (a+(i*d) % MOD) % MOD;
			if (res == 0){break;}
		}
		cout << res;
	}
} 
