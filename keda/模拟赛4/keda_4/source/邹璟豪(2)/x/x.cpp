#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int m,n,a[N];
void solve()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]==a[2]) cout<<"2\n";
	else cout<<"4\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	int _;
	cin>>_;
	while(_--) solve();
}
