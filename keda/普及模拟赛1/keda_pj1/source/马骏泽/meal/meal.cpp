#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long 
using namespace std;
int n,ans=1e9;
struct node{
	int a,b;
};
bool cmp(node x,node y){
	return x.b>y.b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	vector<node>v(550);
	for(int i=1;i<=n;i++)cin>>v[i].a>>v[i].b;
	sort(v.begin()+1,v.end(),cmp);
	for(int i=0;i<(1<<n);i++){
		int t1=0,t2=0,e1=0,e2=0;
		for(int j=1;j<=n;j++){
			if(i>>(j-1)&1){
				t1+=v[j].a;
				e1=max(e1,t1)+v[j].b;
			}else{
				t2+=v[j].a;
				e2=max(e2,t2)+v[j].b;
			}
		}
		ans=min(ans,max(e1,e2));
	}cout<<ans;
	return 0;
}
