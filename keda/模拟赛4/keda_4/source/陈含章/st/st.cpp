#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,m,sum[1000005],cnt,ans;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int len=m;len<=n;len+=m){
        int k=len/m;
        cnt=0;
        for(int i=1;i<=m;i++) sum[i]=0;
        for(int i=1;i<=len;i++) sum[a[i]]++;
        for(int i=1;i<=m;i++) if(sum[i]!=k) cnt++;
        ans+=(cnt==0);
        for(int l=2,r=len+1;r<=n;l++,r++){
            if(a[l-1]==a[r]){
                ans+=(cnt==0);
                continue;
            }
            sum[a[l-1]]--;
            sum[a[r]]++;
            if(sum[a[l-1]]==k) cnt--;
            else if(sum[a[l-1]]==k-1) cnt++;
            if(sum[a[r]]==k) cnt--;
            else if(sum[a[r]]==k+1) cnt++;
            ans+=(cnt==0);
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("st.in","r",stdin);
    freopen("st.out","w",stdout);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}