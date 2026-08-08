#include<bits/stdc++.h>
using namespace std;
int n, ans=1e9;
struct P{int a,b;}p[505];
bool cmp(P x,P y){return x.b>y.b;}
void dfs(int u, int t1, int t2){
    if(max(t1,t2)>=ans) return;
    if(u==n){ans=min(ans,max(t1,t2));return;}
    dfs(u+1, max(t1+p[u].b, p[u].a), t2); 
    dfs(u+1, t1, max(t2+p[u].b, p[u].a)); 
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].a>>p[i].b;
    sort(p,p+n,cmp);
    dfs(0,0,0);
    cout<<ans<<endl;
}
