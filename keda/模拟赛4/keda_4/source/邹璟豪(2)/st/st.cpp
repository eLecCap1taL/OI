#include<bits/stdc++.h>
#include<time.h>
using namespace std;
const int N=1e6+5,BASE=1331,MOD=1e9+7;
int n,m,a[N];
long long tx[N],h[N],s[N],x[N];
map <long long,int> mp;
mt19937 myrand(chrono::system_clock::now().time_since_epoch().count());
long long ksm(long long a,int b,long long p)
{
	long long ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
long long getinv(long long x)
{
	return ksm(x,MOD-2,MOD);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long X=0;
	for(int i=1;i<=m;i++) h[i]=myrand()%MOD,X=(X+h[i])%MOD;
	for(int i=1;i<=n;i++) s[i]=(s[i-1]+h[a[i]])%MOD;
	long long cnt=0;
	long long T=X*getinv(m)%MOD;
	for(int i=1;i<=n;i++) x[i]=((s[i]-i*T%MOD)%MOD+MOD)%MOD;
	
//	cout<<X<<" "<<T<<"\n";
//	for(int i=1;i<=m;i++) cout<<h[i]<<" ";
//	cout<<"\n\n\n";
//	for(int i=1;i<=n;i++) cout<<s[i]<<" "<<x[i]<<" "<<"\n";
	
	for(int i=0;i<=m-1;i++)
	{
//		cout<<"i:"<<i<<"\n";
		for(int j=i;j<=n;j+=m) mp[x[j]]++;
		for(auto x:mp)
		{
//			cout<<x.first<<" "<<x.second<<"\n";
			long long o=x.second;
			cnt+=o*(o-1)/2;
		}
//		cout<<"\n";
		mp.clear();
	}
	cout<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("st.in","r",stdin);
	freopen("st.out","w",stdout); 
	int _;
	cin>>_;
	while(_--) solve();
}
