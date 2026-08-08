#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
int n;
int a[455];
int lc[455],rc[455];
int dp[455][2][455];
int tmp[2][455];
int dfs(int u){
    int sz=1;
    dp[u][0][1]=0;
    dp[u][1][0]=0;
    int lv=lc[u],rv=rc[u];
    if(lv!=-1){
        int szl=dfs(lv);
        for(int c=0;c<=1;c++)
            for(int k=0;k<=sz+szl;k++) tmp[c][k]=INF;
        for(int cu=0;cu<=1;cu++){
            for(int k1=0;k1<=sz;k1++){
                if(dp[u][cu][k1]==INF)continue;
                for(int cv=0;cv<=1;cv++){
                    int cost=(cu!=cv)?a[lv]:0;
                    for(int k2=0;k2<=szl;k2++){
                        if(dp[lv][cv][k2]==INF)continue;
                        tmp[cu][k1+k2]=min(tmp[cu][k1+k2],dp[u][cu][k1]+dp[lv][cv][k2]+cost);
                    }
                }
            }
        }
        sz+=szl;
        for(int c=0;c<=1;c++)
            for(int k=0;k<=sz;k++) dp[u][c][k]=tmp[c][k];
    }
    if(rv!=-1){
        int szr=dfs(rv);
        for(int c=0;c<=1;c++)
            for(int k=0;k<=sz+szr;k++) tmp[c][k]=INF;
        for(int cu=0;cu<=1;cu++){
            for(int k1=0;k1<=sz;k1++){
                if(dp[u][cu][k1]==INF)continue;
                for(int cv=0;cv<=1;cv++){
                    int cost=(cu!=cv)?a[rv]:0;
                    for(int k2=0;k2<=szr;k2++){
                        if(dp[rv][cv][k2]==INF)continue;
                        tmp[cu][k1+k2]=min(tmp[cu][k1+k2],dp[u][cu][k1]+dp[rv][cv][k2]+cost);
                    }
                }
            }
        }
        sz+=szr;
        for(int c=0;c<=1;c++)
            for(int k=0;k<=sz;k++)
				dp[u][c][k]=tmp[c][k];
    }
    return sz;
}
signed main(){
    freopen("still.in","r",stdin);
    freopen("still.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2)sum+=a[i];
    }
    for(int i=1;i<=n;i++) lc[i]=-1,rc[i]=-1;
    for(int i=2;i<=n;i++){
        int fa=i/2;
        if(lc[fa]==-1)lc[fa]=i;
        else rc[fa]=i;
    }
    for(int i=1;i<=n;i++)
        for(int c=0;c<=1;c++)
            for(int k=0;k<=n;k++) dp[i][c][k]=INF;
    dfs(1);
    int minn=min(dp[1][0][n/2],dp[1][1][n/2]);
    cout<<sum-minn<<endl;
    return 0;
}
