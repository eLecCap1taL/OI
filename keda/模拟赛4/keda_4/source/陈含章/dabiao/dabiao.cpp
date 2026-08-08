#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>prime,tmp;
int cnt=24;
string s="";
void dfs(int u,int lst){
    if(u==0){
        cnt+=2+tmp.size()*2;
        s+="{";
        for(int i=tmp.size()-1;i>0;i--) s+=to_string(tmp[i])+",";
        s+=to_string(tmp[0])+"},";
        return;
    }
    for(int i=lst;i>=0;i--){
        if(u>=prime[i]){
            tmp.emplace_back(prime[i]);
            dfs(u-prime[i],i);
            tmp.pop_back();
        }
    }
}
bool np[1000005];
signed main(){
    freopen("dabiao.in","r",stdin);
    freopen("dabiao.out","w",stdout);
    s+="vector<vector<int>>ans={";
    for(int i=2;i<=1e6;i++){
        if(!np[i]) prime.emplace_back(i);
        for(int j=0;j<prime.size()&&prime[j]*i<=1e6;j++){
            np[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    int l,r;
    cin>>l>>r;
    for(int i=2;i<=1e6;i++){
        dfs(i,prime.size()-1);
        if(cnt>=r) break;
    }
    for(int i=l-1;i<r;i++) cout<<s[i];
    cout<<endl;
    return 0;
}