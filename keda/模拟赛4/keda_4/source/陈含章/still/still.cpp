#include<bits/stdc++.h>
using namespace std;
const int MAXN=1010;
struct edge{
    int u,v,w,nxt;
}e[MAXN];
int pos,head[MAXN];
void addEdge(int u,int v,int w){
    e[++pos]={u,v,w,head[u]};
    head[u]=pos;
}
int n,a[500],f[510][510][2],siz[510];
void dfs(int u,int fa){
    siz[u]=1;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
void dfs1(int u,int fa){
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v,w=e[i].w;
        if(v==fa) continue;
        dfs1(v,u);
        for(int j=0;j<=siz[v];j++){
            int k=siz[v]-j;
            f[u][j+1][0]
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) addEdge(i/2,i,a[i]),addEdge(i,i/2,a[i]);
    dfs(1,0);
    dfs1(1,0);
    cout<<max(f[1][n/2][0],f[1][n/2][1])<<endl;
    return 0;
}