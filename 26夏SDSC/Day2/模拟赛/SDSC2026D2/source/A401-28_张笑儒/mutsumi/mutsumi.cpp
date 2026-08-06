#include<bits/stdc++.h>
using namespace std;
int n , ans;
bool vis[805];
struct node{
	int num , id;
}a[805];
void dfs(int step) {
	ans = max(ans , step);
	for(int i = 1 ; i < n ; i++) {
		int tmp = 0;
		bool flag = 0;
		if(vis[i] == 0 && a[i].num == a[i].id) {
			vis[i] = 1;
			for(int j = i + 1 ; j <= n ; j++) {
				if(vis[j] == 0) {
					if(!flag) vis[j] = 1 , flag = 1 , tmp = j;
					else a[j].id -= 2;
				}
			}
			if(tmp == 0) continue;
			dfs(step + 1);
			vis[i] = 0 , vis[tmp] = 0;
			for(int j = tmp + 1 ; j <= n ; j++) {
				if(vis[j] == 0) {
					a[j].id += 2;
				}
			}
		}
	}
}
int main() {
	freopen("mutsumi.in" , "r" , stdin);
	freopen("mutsumi.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i].num;
		a[i].id = i;
	}
	dfs(0);
	cout << ans;
	return 0;
}
