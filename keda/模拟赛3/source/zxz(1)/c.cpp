#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> a;
int best=0;
void dfs(vector<int> cur,vector<int> S){
    if(cur.empty()){
        sort(S.begin(),S.end());
        int cnt=1,mx=1;
        for(int i=1;i<(int)S.size();i++){
            if(S[i]==S[i-1]+1)cnt++;
            else cnt=1;
            mx=max(mx,cnt);
        }
        best=max(best,mx);
        return;
    }
    int mid=cur.size()/2;
    int val=cur[mid];
    S.push_back(val);
    vector<int> cur2=cur;
    cur2.erase(cur2.begin()+mid);
    if(cur2.empty()){
        dfs(cur2,S);
        return;
    }
    for(int i=0;i<(int)cur2.size();i++){
        vector<int> cur3=cur2;
        cur3.erase(cur3.begin()+i);
        dfs(cur3,S);
    }
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
    cin>>n;
    a.resize(2*n+1);
    for(int i=0;i<2*n+1;i++)cin>>a[i];
    if(n<=8){
        dfs(a,{});
        cout<<best<<"\n";
    }
	else{
        int ans=0;
        for(int it=0;it<100000;it++){
            vector<int> cur=a,s;
            while(!cur.empty()){
                int mid=cur.size()/2;
                s.push_back(cur[mid]);
                vector<int> cur2=cur;
                cur2.erase(cur2.begin()+mid);
                if(cur2.empty()){
					cur=cur2;
					break;
				}
                int idx=rand()%cur2.size();
                cur2.erase(cur2.begin()+idx);
                cur=cur2;
            }
            sort(s.begin(),s.end());
            int cnt=1,mx=1;
            for(int i=1;i<(int)s.size();i++){
                if(s[i]==s[i-1]+1)cnt++;
                else cnt=1;
                mx=max(mx,cnt);
            }
            ans=max(ans,mx);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
