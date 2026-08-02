#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, k, a[N][N], ans[N][N], cnt[N];

void work_1(){
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= n;j ++){
			int mn = min(n - i + 1, n - j + 1), flag = 0;
			for (int l = 1;l <= n;l ++) cnt[l] = 0;
			for (int len = 1;len <= mn;len ++){
				for (int l = i;l < i + len;l ++)
					cnt[a[l][j + len - 1]] ++;
				for (int l = j;l < j + len;l ++)
					cnt[a[i + len - 1][l]] ++;
				int res = 0;
				for (int l = 1;l <= n;l ++)
					res += (cnt[l] != 0);
//				printf ("%d %d %d: %d\n", i, j, len, res);
				if (res > k) break; 
				ans[i][j] = len;
			}
		}
	}
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= n;j ++)
			printf ("%d ", ans[i][j]);
		puts(" ");
	}
}

void work_2(){
	if (k >= 2){
		for (int i = 1;i <= n;i ++){
			for (int j = 1;j <= n;j ++)
				printf ("%d ", min(n - i, n - j));
			puts(" ");
		}
		return;
	}
	int now[N][N];
	memset (now, 0, sizeof now);
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= n;j ++){
			if (a[i - 1][j] != a[i][j - 1]){
				a[i][j] = 1;
				break;
			}
			if (a[i][j] != a[i - 1][j]){
				a[i][j] = 1;
				break;
			}
			int len = min(now[i - 1][j], now[i][j - 1]);
			if (a[i - len][j - len] == a[i][j])
				a[i][j] = len + 1;
			else a[i][j] = len;
		}
	}
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= n;j ++){
			int mx = min(n - i, n - j);
			for (int len = 1;len <= mx;len ++){
				if (a[i + len][j + len] >= len) ans[i][j] = len;
				else break;
			}
		}
	}
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= n;j ++)
			printf ("%d ", ans[i][j]);
		puts(" ");
	}
}

void work_3(){
}

int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	int flag_2 = 1;
	scanf ("%d%d", &n, &k);
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= n;j ++){
			scanf ("%d", &a[i][j]);
			if (a[i][j] >2)flag_2 = 0;
		}
	if (n <= 50) work_1();
	else if (flag_2) work_2();
	else if (k == 2) work_3();
	
	
	return 0;
} 
