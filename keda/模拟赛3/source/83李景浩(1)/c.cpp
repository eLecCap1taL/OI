#include <bits/stdc++.h>
using namespace std;
int N,ans;
int calc(vector<int> S) {
    vector<bool> vis(410,0);
    for(int x:S) vis[x]=1;
    int res=1,cur=0;
    for(int i=1;i<=2*N+1;i++){
        if(vis[i]) cur++,res=max(res,cur);
        else cur=0;
    }
    return res;
}
void dfs(vector<int> arr,int step,vector<int> S){
    int len=arr.size();
    int mid=len/2;
    int val=arr[mid];
    S.push_back(val);
    arr.erase(arr.begin()+mid); 
    if(step==N+1){
        ans=max(ans,calc(S));
        return;
    }
    for(int i=0;i<arr.size();i++){
        vector<int>nxt=arr;
        nxt.erase(nxt.begin()+i);
        dfs(nxt,step+1,S);
    }
}
int main() {
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin>>N;
    int L=2*N+1;
    vector<int>a(L);
    for(int i=0;i<L;i++) cin>>a[i];
    ans=0;
    dfs(a,1,{});
    cout<<ans<<endl;
    return 0;
}