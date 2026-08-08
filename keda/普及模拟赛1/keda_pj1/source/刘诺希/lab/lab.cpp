#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int a,b,c,d;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	a=b=2e9;
	c=d=-2e9;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		a=min(a,x);
		b=min(b,y);
		c=max(c,x);
		d=max(d,y);
	}
	a--; 
	b--;
	c++;
	d++;
	cout<<a<<" "<<b<<endl;
	cout<<c<<" "<<d<<endl;
	return 0;
}

