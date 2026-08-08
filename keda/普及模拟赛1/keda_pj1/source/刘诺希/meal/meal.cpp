#include<bits/stdc++.h>
using namespace std;
int n;
struct P{
	int a,b;
}p[205];
bool cmp(P x,P y){
	return x.b>y.b;
}
int dp[200005],nd[200005];
int main(){
	cin>>n;
	int sa=0;
	for(int i=0;i<n;i++){
		cin>>p[i].a>>p[i].b;
		sa+=p[i].a;
	}
	sort(p,p+n,cmp);
	for(int i=0;i<=sa;i++){
		dp[i]=1e9;
	}
	dp[0]=0;
	int s=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=sa;j++){
			nd[j]=1e9;
		}
		for(int j=0;j<=s;j++){
			if(dp[j]>=1e9){
				continue;
			}
			nd[j+p[i].a]=min(nd[j+p[i].a],max(dp[j],j+p[i].a+p[i].b));
			nd[j]=min(nd[j],max(dp[j],s-j+p[i].a+p[i].b));
		}
		s+=p[i].a;
		for(int j=0;j<=sa;j++){
			dp[j]=nd[j];
		}
	}
	int ans=1e9;
	for(int j=0;j<=sa;j++){
		ans=min(ans,dp[j]);
	}
	cout<<ans;
	return 0;
}

