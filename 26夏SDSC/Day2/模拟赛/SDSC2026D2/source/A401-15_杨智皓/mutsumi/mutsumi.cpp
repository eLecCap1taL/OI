#include<bits/stdc++.h>
using namespace std;
int n, pos = -1;
bool vis[2000005];
int a[200005];
int ans;
int len;

int main(){
	freopen("mutsumi.in", "r", stdin);
	freopen("mutsumi.out", "w", stdout);
	int n; cin >> n; len = n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] == i && i != n)
			pos = i;}
	if (pos != -1){
		ans ++;
		vis[pos] = 1;
		vis[pos+1] = 1;
		len -= 2;}
	else{
		cout << "0";
		return 0;
	}
	while(pos != -1){
		pos = -1; int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (!vis[i]) cnt ++;
			if (cnt == a[i] && cnt != len)
				pos = i;
		}
		if (pos != -1){
			ans ++;
			len -= 2;
			vis[pos] = 1;}
	}
	cout << ans;
} 
