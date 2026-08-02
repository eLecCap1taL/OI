#include<bits/stdc++.h>
using namespace std;
int n , k;
int a[501][501];
vector<pair<int , int> > d[501][501];
int ans[501][501];
bool vis[505];
int main() {
	freopen("anon.in" , "r" , stdin);
	freopen("anon.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = n ; i >= 1 ; i--) {
		for(int j = n ; j >= 1 ; j--) {
			memset(vis , 0 , sizeof vis);
			int l1 = 0 , l2 = 0 , l3 = 0 , cnt = 1;
			d[i][j].emplace_back(make_pair(1 , a[i][j]));
			bool flag1 = (i == n) , flag2 = (j == n) , flag3 = (i == n || j == n);
			vis[a[i][j]] = 1;
			while(cnt <= k) {
				int minn = 0x3f3f3f3f;
				pair<int , int> min1 , min2 , min3;
				if(!flag1) {
					while(l1 < d[i + 1][j].size() && vis[d[i + 1][j][l1].second]) l1++;
					if(l1 == d[i + 1][j].size()) flag1 = 1;
					min1 = d[i + 1][j][l1];
					if(i + min1.first > n || j + min1.first > n) flag1 = 1;
				}
				if(!flag2) {
					while(l2 < d[i][j + 1].size() && vis[d[i][j + 1][l2].second]) l2++;
					if(l2 == d[i][j + 1].size()) flag2 = 1;
					min2 = d[i][j + 1][l2];
					if(i + min2.first > n || j + min2.first > n) flag2 = 1;
				}
				if(!flag3) {
					while(l3 < d[i + 1][j + 1].size() && vis[d[i + 1][j + 1][l3].second]) l3++;
					if(l3 == d[i + 1][j + 1].size()) flag3 = 1;
					min3 = d[i + 1][j + 1][l3];
					if(i + min3.first > n || j + min3.first > n) flag3 = 1;
				}
				if(!flag1 && !vis[min1.second]) minn = min(minn , min1.first);
				if(!flag2 && !vis[min2.second]) minn = min(minn , min2.first);
				if(!flag3 && !vis[min3.second]) minn = min(minn , min3.first);
				if(minn == 0x3f3f3f3f) break;
				if(minn == min1.first) {
					cnt++;
					l1++;
					d[i][j].emplace_back(minn + 1 , min1.second);
					vis[min1.second] = 1;
					continue;
				}
				if(minn == min2.first) {
					cnt++;
					l2++;
					d[i][j].emplace_back(minn + 1 , min2.second);
					vis[min2.second] = 1;
					continue;
				}
				if(minn == min3.first) {
					cnt++;
					l3++;
					d[i][j].emplace_back(minn + 1 , min3.second);
					vis[min3.second] = 1;
					continue;
				}
			}
			if(d[i][j].size() <= k) ans[i][j] = min(n - i + 1 , n - j + 1);
			else ans[i][j] = d[i][j][k].first - 1;
		}
	}
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}





