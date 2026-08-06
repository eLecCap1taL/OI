#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,m;
vector<string>g;
int cnt;
bool fl=1,vis[35][35];
bool ra(){
    for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)	vis[i][j]=0;
    if(g[0][0]=='#')return 0;
    vis[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j])continue;
            if(i+1<n&&g[i+1][j]=='-')vis[i+1][j]=1;
            if(j+1<m&&g[i][j+1]=='-')vis[i][j+1]=1;
        }
    }
    return vis[n-1][m-1];
}
vector<vector<pair<int,int>>>p;
void gp(int x,int y,vector<pair<int,int>>&cur){
    if(x==n-1 && y==m-1){
        p.push_back(cur);
        return;
    }
    if(x+1<n&&g[x+1][y]=='-'){
        cur.push_back({x+1,y});
        gp(x+1,y,cur);
        cur.pop_back();
    }
    if(y+1<m&&g[x][y+1]=='-'){
        cur.push_back({x,y+1});
        gp(x,y+1,cur);
        cur.pop_back();
    }
}
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
    cin>>n>>m;
    g.resize(n);
    for(int i=0;i<n;i++)cin>>g[i];
    cnt=0;
    fl=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='-')cnt++;
            else fl=0;
        }
    }
    if(fl){
        cout<<(n+m-1)%mod<<"\n";
        return 0;
    }
    if(!ra()){
        int ans=1;
        for(int i=0;i<cnt;i++)ans=ans*2%mod;
        cout<<ans<<"\n";
        return 0;
    }
    else{
        vector<pair<int,int>>c;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]=='-')c.push_back({i,j});
        int S=c.size();
        vector<pair<int,int>>cur;
        cur.push_back({0,0});
        gp(0,0,cur);
        int ans=0;
        for(int mask=0; mask<(1<<S); mask++){
            bool ok=1;
            for(auto &path: p){
                int cnt=0;
                for(auto &pa: path){
                    int idx=-1;
                    for(int t=0;t<S;t++)if(c[t]==pa){
						idx=t;
						break;
					}
                    if(idx!=-1&&(mask>>idx)&1)cnt++;
                }
                if(cnt!=1){
					ok=0;
					break;
				}
            }
            if(ok)ans++;
        }
        cout<<ans%mod<<"\n";
        return 0;
    }
    cout<<0<<"\n";
    return 0;
}
