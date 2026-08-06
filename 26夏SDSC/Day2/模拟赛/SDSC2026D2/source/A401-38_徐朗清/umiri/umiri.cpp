#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<iomanip>
#include<set>
#define ll long long
using namespace std;
const int N=1e2+5;
const ll INF=1e18;
ll n,m,a[N],b[N],v[N];
int main() {
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>a[i]>>b[i];
		while(b[i]) {
			ll fi_min=INF,se_min=INF,cnt=0;
			for(int j=1; j<=a[i]; j++) {
				if(v[j]==fi_min) cnt++;
				else if(v[j]<fi_min) {
					se_min=fi_min;
					fi_min=v[j],cnt=1;
				} else if(v[j]<se_min)
					se_min=v[j];
			}
//			cout<<"MIN: "<<fi_min<<" "<<se_min<<' '<<cnt<<endl;
			if(se_min==INF) {
				ll maxadd=b[i]/a[i];
				b[i]=b[i]-maxadd*a[i];
				for(int j=1; j<=a[i]; j++)
					v[j]+=maxadd;
				for(int j=1; j<=a[i]; j++) {
					if(b[i]==0) break;
					v[j]++,b[i]--;
				}
			} else {
				ll need=se_min-fi_min;
				ll maxadd=b[i]/cnt;
				if(maxadd<=need) {
				b[i]=b[i]-maxadd*cnt;
					for(int j=1; j<=a[i]; j++) {
						if(v[j]==fi_min) {
							v[j]+=maxadd;
							if(b[i]!=0)v[j]++,b[i]--;
						}
					}
				} else {
				b[i]=b[i]-need*cnt;
					for(int j=1; j<=a[i]; j++)
						if(v[j]==fi_min) v[j]+=need;
				}
			}
//			for(int j=1; j<=n; j++) cout<<v[j]<<' ';
//			cout<<endl;
//			cout<<"rest: "<<b[i]<<endl;
		}
	}
	for(int j=1; j<=n; j++) cout<<v[j]<<'\n';
	return 0;
}
