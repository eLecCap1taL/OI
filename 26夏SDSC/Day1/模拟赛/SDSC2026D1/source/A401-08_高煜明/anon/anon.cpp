#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[501][501],ans[501][501],fl[505]; 
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans[i-1][j-1]>=min(n-i+2,n-j+2)){
				ans[i][j]=min(n-i+1,n-j+1);
				continue;
			}
			else{
				for(int p=1;p<=n;p++){
					fl[p]=0;
				}
				int neko=1;
				fl[a[i][j]]=1;
				ans[i][j]=1;
				for(int op=1;op<=min(n-i,n-j);op++){
					for(int k=j;k<=j+op-1;k++){
						if(!fl[a[i+op][k]]){
							neko++;
							fl[a[i+op][k]]=1;
						}
						if(neko>m){
							break;
						}
					}
					for(int k=i;k<=i+op;k++){
						if(!fl[a[k][j+op]]){
							neko++;
							fl[a[k][j+op]]=1;
						}
						if(neko>m){
							break;
						}
					}
				//	cout<<"C "<<neko<<'\n';
					if(neko<=m){
						ans[i][j]=op+1;
					}
					else{
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
