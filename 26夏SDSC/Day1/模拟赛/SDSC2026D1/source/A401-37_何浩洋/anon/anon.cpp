#include<bits/stdc++.h>
using namespace std;
int a[509][509],n,k,f,h[509][509];
int t[509],g[509][509][509],b[509][509][509];
int e[509],d;
int main() {
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			scanf("%d",&a[i][j]);
			f=max(f,a[i][j]);
			if(!e[a[i][j]]++) d++;
		}
	if(d<=k) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
				printf("%d ",min(n-i+1,n-j+1));
			printf("\n");
		}
		return 0;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			for(int x=1; x<=f; x++)
				g[i][j][x]=g[i][j-1][x],b[i][j][x]=b[i-1][j][x];
			g[i][j][a[i][j]]++,b[i][j][a[i][j]]++;
		}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			int c=0;
			for(int len=0; max(i+len,j+len)<=n; len++) {
				int c=0;
				for(int x=1; x<=f; x++)
					t[x]+=g[i+len][j+len][x]+b[i+len][j+len][x]-g[i+len][j-1][x]-b[i-1][j+len][x];
				t[a[i+len][j+len]]--;
				for(int x=1; x<=f; x++)
					if(t[x]) c++;
				if(c>k) {
					h[i][j]=len;
					break;
				}
			}
			if(!h[i][j])
				h[i][j]=min(n-i+1,n-j+1);
			memset(t,0,sizeof t);
		}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			printf("%d ",h[i][j]);
		printf("\n");
	}
	return 0;
}

