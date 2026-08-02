#include<bits/stdc++.h>
using namespace std;
const int N=5e2+2;
struct node {
	int x,y;
};
int n,k,a[N][N],num[N][N][N];
bool check(node l,node r) {
	int ans=0;
	for(int i=1; i<=n; i++)
		if(num[i][r.x][r.y]-num[i][l.x-1][r.y]-num[i][r.x][l.y-1]+num[i][l.x-1][l.y-1]) {
			ans++;
			if(ans>k) return 0;
		}
	return 1;
}
int main() {
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			for(int u=1; u<=n; u++)
				num[u][i][j]=num[u][i-1][j]+num[u][i][j-1]-num[u][i-1][j-1];
			num[a[i][j]][i][j]++;
		}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			node l= {i,j},r= {i+min(n-i,n-j),j+min(n-i,n-j)};
			while(l.x<r.x&&l.y<r.y) {
				node mid= {l.x+(r.x-l.x+1)/2,l.y+(r.y-l.y+1)/2};
				if(check({i,j},mid))
					l=mid;
				else r.x=mid.x-1,r.y=mid.y-1;
			}
			cout<<l.x-i+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

