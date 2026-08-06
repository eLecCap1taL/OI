#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int T;

int main(){
	freopen("uika.in","r", stdin);
	freopen("uika.out", "w", stdout);
	cin >> T;
	while(T--){
		int n, k, m; cin >> n >> k >> m;
		string ans = "NO";
		for (int i = 1; i <= m; i++)
			cin >> a[i];
		
		for (int i = 1; i <= m; i++){
			int l_num = a[i]-i;
			int r_num = n-a[i]-m+i;
			
			if (l_num == 0 || r_num == 0) continue;
			
			if(l_num%(k-1) == 0 && r_num%(k-1) == 0){
				ans = "YES"; break;}
				
			while(l_num >= (k-1)/2 && r_num >= (k-1)/2){
				l_num -= ((k-1)/2);
				r_num -= ((k-1)/2);
				if (l_num %(k-1) == 0 && r_num%(k-1) == 0){
					ans = "YES"; break; break;}
			}
		}
		cout << ans << endl;
	}
}
