#include <bits/stdc++.h>

using namespace std;

const int N = 810;

int a[N], n, c[N];
int work(int a[], int x){ 
	int b[N];
	for (int i = 1;i <= x;i ++)
		b[i] = a[i];
	int ans = 0;
	for (int i = 1;i < x;i ++){
//		cout << i << " " << (b[i] == i) << endl;
		if (b[i] == i){
			for (int j = 1, k = 1;j <= x;j ++){
				if (j == i || j == i + 1) continue;
//				cout << j << " " << k << endl;
				c[k] = b[j];k ++;
			}
			ans = max(ans, work(c, x - 2) + 1);
		}
	}
	return ans;
}

int main(){
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	
	scanf ("%d", &n);
	for (int i = 1;i <= n;i ++)
		scanf ("%d", &a[i]);
	
	cout << work(a, n);
	
	
	return 0;
}
