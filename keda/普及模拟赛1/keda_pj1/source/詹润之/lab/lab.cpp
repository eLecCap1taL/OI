#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2*1e5;
int n,x,y;
int lx=1e9,rx,ly=1e9,ry;
int main(){
	freopen("lab.in","r",stdin);
	freopen("lab.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>x>>y;
    	lx=min(lx,x);
    	rx=max(rx,x);
    	ly=min(ly,y);
    	ry=max(ry,y);
	}
	cout<<lx-1<<" "<<ly-1<<endl;
	cout<<rx+1<<" "<<ry+1;
	fclose(stdin);
	fclose(stdout);
}
