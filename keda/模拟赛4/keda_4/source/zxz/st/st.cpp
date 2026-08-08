#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,a[1000005],cnt[1000005];
signed main(){
    freopen("st.in","r",stdin);
    freopen("st.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=0;
        for(int l=1;l<=n;l++){
            for(int i=1;i<=m;i++)	cnt[i]=0;
            int diff=0;
            for(int r=l;r<=n;r++){
                int x=a[r];
                if(cnt[x]==0)diff++;
                cnt[x]++;
                if(diff==m){
                    int v=cnt[1];
                    bool ok=1;
                    for(int i=2;i<=m;i++)if(cnt[i]!=v){ok=0;break;}
                    if(ok)ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
