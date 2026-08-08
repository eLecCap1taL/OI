#include<bits/stdc++.h>
#include<time.h>
using namespace std;
const int N=1e6+5,BASE=1331,MOD=1e9+7;
int n,m,a[N];
long long tx[N],h[N],s[N];
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
	long long dx=getinv(X);	
	for(int i=1;i<=n;i++) s[i]=(s[i-1]+h[a[i]])%MOD;
	int cnt=0;
	for(int i=m;i<=n;i++)
	{
		for(int j=i-m;j>=0;j-=m)
		{
			long long hh=((s[i]-s[j])%MOD+MOD)%MOD;
			long long k=hh*dx%MOD;
			if(i-j==k*m) cnt++; 
		}
	}
	cout<<cnt<<"\n";
}
int main()
{
	srand(time(0)); 
//	freopen("st.in","r",stdin);
//	freopen("st.out","w",stdout); 
	int _;
	cin>>_;
	while(_--) solve();
}
