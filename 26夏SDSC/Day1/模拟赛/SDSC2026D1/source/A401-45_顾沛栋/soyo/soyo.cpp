#include <bits/stdc++.h>

using namespace std;

int n, x, y, flag_1, flag_2;

void work_1(){
	cout << n << endl;
}
int f[300010];
void work_2(){
	f[0] = f[1] = 1;
	for (int i = 2;i <= n;i ++)
		f[i] = f[i - 1] + f[i - 2];
	cout << f[n] << endl;
}

int main(){
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	scanf ("%d", &n);
	for (int i = 1;i <= n;i ++){
		scanf ("%d%d", &x, &y);
		if (x < y) swap(x, y);
		if (x == i + 1) flag_2 = 0;
		if (y != i)flag_1 = 0;
	}
	if (flag_1)work_1();
	else work_2(); 
	
	return 0;
}
