#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int f[N][2];
int main() {
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	int n;
	cin>>n;
	int l,r;
	for(int i=1; i<n; i++)
		cin>>l>>r;
	f[1][0]=f[1][1]=1;
	for(int i=2; i<n; i++) {
		f[i][0]=f[i-1][1];
		f[i][1]=f[i-1][0]+f[i-1][1];
	}
	cout<<f[n-1][0]+f[n-1][1];
	return 0;
}

