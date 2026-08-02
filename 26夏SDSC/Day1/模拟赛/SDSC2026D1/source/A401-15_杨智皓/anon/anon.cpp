#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
int pre[MAXN][MAXN][MAXN];
int a[MAXN][MAXN];
int n, k, max_a;

int check(int x, int y, int len){
	int cnt = 0;
	for (int i = 1; i <= max_a; i++){
		if (pre[x+len-1][y+len-1][i] - pre[x-1][y+len-1][i] - pre[x+len-1][y-1][i] + pre[x-1][y-1][i] > 0)
			cnt ++;
	}
	return cnt;
}

int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			cin >> a[i][j]; max_a = max(max_a, a[i][j]);
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= max_a; k++){
			pre[i][j][k] = pre[i-1][j][k] + pre[i][j-1][k] - pre[i-1][j-1][k];
			if (a[i][j] == k)
			pre[i][j][k] ++;
			}
		}
	for (int i = 1; i <= n; i++){
		if (i != 1)cout << endl;
		for (int j = 1; j <= n; j ++){
			int r = min(n-i+1, n-j+1);
			int l = 1;
			int mid = 0;
			while(l <= r){
				int mid = (l+r)/2;
				int tmp = check(i, j, mid);
				if (tmp <= k)
					l = mid+1;
				if (tmp > k)
					r = mid-1;
			}
			cout << r << " ";
		}
	}

}
/*
5 4
1 2 3 3 2
4 5 1 3 1
2 3 5 5 5
5 3 1 2 3
3 3 3 1 2
*/
