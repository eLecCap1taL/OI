#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s,t;
string dp[55][55],dp2[55][55];
bool vis[55][55];
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>s>>t;
    int n=s.size();
    vis[0][0]=1;
    for(int i=1;i<=n;i++){
        char l=s[i-1],r=t[i-1];
        for(int j=0;j<=i;j++){
            if(vis[i-1][j]){
                if(!vis[i][j]||dp[i-1][j]+dp2[i-1][j]>dp[i][j]+dp2[i][j]){
                    dp[i][j]=dp[i-1][j];
                    dp2[i][j]=dp2[i-1][j];
                    vis[i][j]=1;
                }
            }
            if(j>0&&vis[i-1][j-1]){
                string ns=dp[i-1][j-1]+l,nt=dp2[i-1][j-1]+r;
                if(!vis[i][j]||ns+nt>dp[i][j]+dp2[i][j]){
                    dp[i][j]=ns;
                    dp2[i][j]=nt;
                    vis[i][j]=1;
                }
            }
        }
    }
    string ans;
    for(int j=0;j<=n;j++)
		if(vis[n][j])
			ans=max(ans,dp[n][j]+dp2[n][j]);
    cout<<ans<<'\n';
}
