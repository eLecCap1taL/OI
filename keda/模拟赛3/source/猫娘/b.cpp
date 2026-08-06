#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool vis[110][110];
string ans,dp[110][110],s,s1;
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>s>>s1; 
	n=s.size();
	s=" "+s,s1=" "+s1;
	vis[0][0]=true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(!vis[i-1][j]) continue;
			if((!vis[i][j])||dp[i][j]<dp[i-1][j]){
				dp[i][j]=dp[i-1][j];
				vis[i][j]=true;
			}
			if(j+1<=n){
				string tmp=dp[i-1][j].substr(0,j)+s[i]+dp[i-1][j].substr(j)+s1[i];
				if((!vis[i][j+1])||dp[i][j+1]<tmp){
					vis[i][j+1]=true;
					dp[i][j+1]=tmp;
				}
			}
		}
	}
	for(int i=0;i<=n;i++) if(vis[n][i]) ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}