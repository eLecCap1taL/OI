#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    double sum=0,sum1=0;
    int x,y;
    cin>>x>>y;
    int n=x*2+y;
    for(int i=1;i<=n;i++) sum+=1.0/i,sum1+=1.0/i*(i<=x);
    sum-=0.5*sum1;
    printf("%.15lf\n",sum);
    return 0;
}