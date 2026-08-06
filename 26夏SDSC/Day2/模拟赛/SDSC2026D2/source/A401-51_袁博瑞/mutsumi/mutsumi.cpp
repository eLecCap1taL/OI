#include<bits/stdc++.h>
using namespace std;
const int N=8e2+2;
int a[N];
int main() {
	freopen("mutsumi.in","r",stdin);
	freopen("mutsumi.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	int ans=0;
	bool f=1;
	while(f==1) {
		f=0;
		for(int i=n-1; i>=1; i--)
			if(a[i]==i) {
				f=1;
				ans++;
				for(int j=i; j<=n-2; j++)
					a[j]=a[j+2];
				break;
			}
	}
	cout<<ans;
	return 0;
}

