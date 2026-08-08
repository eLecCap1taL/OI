#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,m,T;
int qpow(int a,int b){
    int res=1;
    while(b>0){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
vector<int> solve(vector<int>&s){
    int n=s.size();
    vector<int>res(n+1,0);
    for(int i=1;i<n;i++){
        int j=res[i-1];
        while(j>0&&s[i]!=s[j])j=res[j-1];
        if(s[i]==s[j])j++;
        res[i]=j;
    }
    return res;
}
signed main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
	cin>>T;
    while(T--){
        cin>>m>>n;
        vector<int>b(n,0);
        for(int i=0;i<n;i++)cin>>b[i];
        vector<int> pi=solve(b);
        int ans=0;
        int cur=n;
        while(cur>0){
            ans=(ans+qpow(m,cur))%MOD;
            cur=pi[cur-1];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
