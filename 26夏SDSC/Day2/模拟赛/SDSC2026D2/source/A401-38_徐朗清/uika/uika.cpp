#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<iomanip>
#include<set>
#define ll long long
using namespace std;
const int N=2e3+5;
int t;
int n,k,m,uni;
int a[N],b[N],vis[N];
int st[N],q[N];
int c[N],top,f;
bool check(){
	bool f1=0,f2=0;
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			for(int k=l+1;k<=r-1;k++){
				if(vis[l]==1&&vis[r]==1&&vis[k]!=1) f1=1;
				if(vis[l]==2&&vis[r]==2&&vis[k]==0) f2=1;
			}
		}
	}
	return f1&f2;
}
void solve() {
	f=1;
	int lg=1;
	for(int i=1; i<=n; i++)
		lg=lg*3;
	lg--;
	for(int j=0; j<=lg; j++) {
		for(int i=1,k=j; i<=n; i++)
			vis[i]=k%3,k/=3;
		int top=1;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				if(a[i]!=b[top]) break;
				else top++;
				if(top==m) 
					if(check()) f=0;
			}
		}
	}
}
int main() {
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		f=0;
		cin>>n>>k>>m;
		for(int i=1; i<=n; i++) a[i]=0;
		for(int i=1; i<=m; i++) cin>>b[i];
		if((n-m)%(k-1)!=0) {
			cout<<"NO\n";
			continue;
		}
		if(n<=6) solve();
		else {
			int dif=n-m;
			if(dif<=(k-1)*2) f=0;
			else f=1;
		}
		if(f) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
