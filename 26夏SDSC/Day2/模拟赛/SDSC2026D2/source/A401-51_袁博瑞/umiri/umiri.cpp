#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int x[N];
int main() {
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>a>>b;
		for(int c=1; c<=b; c++) {
			int minn=x[1],d=1;
			for(int j=2; j<=a; j++)
				if(x[j]<minn) {
					minn=x[j];
					d=j;
				}
			x[d]++;
		}
	}
	for(int i=1; i<=n; i++)
		cout<<x[i]<<"\n";
	return 0;
}

