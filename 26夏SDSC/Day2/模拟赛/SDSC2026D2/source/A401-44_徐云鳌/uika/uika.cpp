#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 2e6 + 10;

int n,k,m;
int b[maxn];

int solve()
{
	cin >>n >> k>> m;
	for(int i = 1;i<=m;i++) cin >> b[i];
	if((n-m) % (k-1) != 0) return cout <<"NO\n",0;
	bool fl = 0;
	for(int i =1;i<= m;i++)if(b[i] - i>=(k-1)/2 && (n-b[i]+1) - (m-i+1) >=(k-1)/2) fl = 1;
	if(fl) cout << "YES\n";
	else cout <<"NO\n";
	return 0;
}

signed main()
{
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin >> t;
	while(t--) solve();return 0;
} 
