#include<bits/stdc++.h>
#define ll long long
#define u64 unsigned long long

using namespace std;
int n,x,y;
int mix=1e9,miy=1e9,mxx,mxy;
int main(){
	freopen("lab.in","r",stdin);
	freopen("lab.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		mix=min(mix,x);
		miy=min(miy,y);
		mxx=max(mxx,x);
		mxy=max(mxy,y);
	}
	cout<<mix-1<<' '<<miy-1<<endl;
	cout<<mxx+1<<' '<<mxy+1<<endl;
	return 0;
}

