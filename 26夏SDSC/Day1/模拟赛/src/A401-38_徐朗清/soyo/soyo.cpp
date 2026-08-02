#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#define ll long long
using namespace std;
const int N=3e5+5;
const int ll mod=998244353;
int n,uu[N],vv[N],from[N],to[N];
ll f[N][5],ans;
vector<int>e[25];
bool check() {
	for(int i=1; i<=n; i++) {
		if(from[i]==n+1||to[i]==0) continue;
		if(from[i]<to[i]) return 0;
	}
	return 1;
}
void solve() {
	int lg=(1<<(n-1))-1;
//	cout<<lg<<endl;
	for(int i=0; i<lg; i++) {
		for(int j=1; j<=n; j++) e[j].clear(),from[j]=n+1,to[j]=0;
		for(int j=1,k=i; j<=n; j++,k/=2) {
			if(k&1) {
				e[uu[j]].push_back(vv[j]);
				from[vv[j]]=min(from[vv[j]],j);
				to[uu[j]]=max(to[uu[j]],j);
			} else   {
				e[vv[j]].push_back(uu[j]);
				from[uu[j]]=min(from[uu[j]],j);
				to[vv[j]]=max(to[vv[j]],j);
			}
		}
		if(check()) {
			ans++;
//			cout<<ans<<endl;
//			for(int k=1; k<=n; k++) {
//				int len=e[k].size();
//				cout<<k<<" ";
//				for(int j=0; j<len; ++j){
//					int v=e[k][j];
//					cout<<v<<" ";
//				}
//				cout<<endl;
//			}
		}
	}
}
void solve1() {
	f[2][1]=f[2][2]=1;
	for(int i=3; i<=n; i++) {
		f[i][1]=f[i-1][1]+f[i-1][2];
		f[i][2]=f[i-1][1];
		f[i][1]%=mod,f[i][2]%=mod;
	}
	ans=f[n][1]+f[n][2];
	ans=ans%mod;
}
int main() {
	freopen("soyo.in","r",stdin);
	freopen("soyo.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int sta1=1;
	for(int i=1; i<n; i++) {
		cin>>uu[i]>>vv[i];
		if(uu[i]>vv[i]) swap(uu[i],vv[i]);
		if(uu[i]!=vv[i]-1) sta1=0;
	}
	if(n<=15) solve();
	else if(sta1) solve1();
	else ans=n-1;
	cout<<ans<<endl;
	return 0;
}
/*
11
1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 11
11
1 11
2 11
3 11
4 11
5 11
6 11
7 11
8 11
9 11
10 11
*/
