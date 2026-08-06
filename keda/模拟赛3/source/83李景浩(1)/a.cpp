#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main() {
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int x,y;
    scanf("%d%d",&x,&y);
    double n=2*x+y;
    //cout<<n<<endl;
    ll xx=x*x;
    double ln=0,lne=0;
    for(int i=1;i<=n;i++){
        ln+=1.0/i;
        if(i==x){
            lne+=ln;
            //printf("%.10lf\n",lne);
        }
    }
    //printf("%.10lf\n",ln);
    //printf("%.9lf",x+y-(double)2.0*xxn);
    printf("%.10lf",(double)ln-lne/2.0);
    return 0;
}