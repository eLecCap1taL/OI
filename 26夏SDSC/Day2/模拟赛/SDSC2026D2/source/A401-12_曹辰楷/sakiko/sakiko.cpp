#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1145141+10,P=1145141;
int n,a,d,fac=1,len=0;
void solve()
{
	cin>>d>>n>>a;
	vector<int>res;
	res.push_back(0);
	if((d==1&&a+n>=P)||a==0)
	{
		cout<<0<<'\n';
		return;
	}
	d%=P,a%=P;
	fac=1,len=0;
	bitset<N>vis;
	while(!vis[a]&&len<n)
	{
		fac*=a;fac%=P;
		if(!fac)
		{
			cout<<0<<'\n';
			return;
		}
		a=(a+d)%P;
		len++;
		res.push_back(fac);
	}
	cout<<fac*(n/len)+res[n%len]<<'\n';
}
signed main()
{
	freopen("sakiko.in","r",stdin);
	freopen("sakiko.out","w",stdout);
	int _T_;
	cin>>_T_;
	while(_T_--)solve();
}
