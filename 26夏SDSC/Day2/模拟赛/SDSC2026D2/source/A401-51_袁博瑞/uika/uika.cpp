#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int b[N];
vector<int> q;
bool cmp(int a,int b) {
	return a<b;
}
int main() {
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	int T,n,k,m;
	cin>>T;
	while(T--) {
		cin>>n>>k>>m;
		for(int i=1; i<=m; i++)
			cin>>b[i];
		if((n-m)%(k-1)) {
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
	}
	return 0;
}
