#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int n, k, m, b[N];
int cnt[N], la[N];

void work(){
	scanf ("%d%d%d", &n, &k, &m);
	memset (cnt, 0, sizeof cnt);
	memset (la, 0, sizeof la);
	for (int i = 1;i <= m;i ++)
		scanf ("%d", &b[i]);
	for (int i = 1, j = 1;i <= n;i ++){
		if (b[j] == i) cnt[i] = cnt[i - 1], j ++;
		else cnt[i]  = cnt[i - 1] + 1;
	}
	if ((n - m) % (k - 1) != 0){
		puts("NO");
		return;
	}
	
	for (int i = n, j = m;i >= 1;i --){
		if (b[j] == i) la[i] = la[i + 1], j --;
		else la[i] = la[i + 1] + 1;
	}
	int ans = 0;
	for (int i = 2;i < n;i ++)
		if (cnt[i - 1] - ans * (k - 1) == (k >> 1) && la[i + 1] >= (k >> 1))
			ans ++, i += (k >> 1);
	if (ans * (k - 1) != n - m) puts("NO");
	else puts("YES");
}

int main(){
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	
	int t;
	scanf ("%d", &t);
	while (t --) work(); 
	
	return 0;
} 

