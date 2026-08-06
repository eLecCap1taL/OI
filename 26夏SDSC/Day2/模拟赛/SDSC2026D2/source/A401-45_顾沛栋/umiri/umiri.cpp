#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int n, m;
long long a[N];

void work(int x, long long b, int now){
	long long mx = 1e9, id = 0;
	if (x == 1){
		a[1] += b;
		return;
	}
	for (int i = now;i >= 1;i --){
		if (i == 1) a[1] ++, b --, i ++;
		if (a[i] != a[i - 1]){
			if (!b) return;
			a[i] ++;
			b --;
			id = i;
			i ++;
			while (b && i <= x){
				a[i] ++;
				b --;
				i ++;
			}
			if (b == 0) break;
			else {work(x, b, id);break;}
		}
	}
}

int main(){
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	scanf ("%d%d", &n, &m);
	long long b;
	a[0] = -1;
	for (int i = 1, x;i <= m;i ++){
		scanf ("%d%lld", &x, &b);
		work(x, b, x);
	}
	for (int i = 1;i <= n;i ++)
		printf ("%lld\n", a[i]);
	
	return 0;
}
