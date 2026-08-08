#include<bits/stdc++.h>
using namespace std;
int n;
int max1=INT_MIN,max2=INT_MIN;
int min1=INT_MAX,min2=INT_MAX;
int main(){
	freopen("lab.in","r",stdin);
	freopen("lab.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if(x<min1)min1=x;
		if(x>max1)max1=x;
		if(y<min2)min2=y;
		if(y>max2)max2=y;
	}
	cout<<min1-1<<' '<<min2-1<<endl<<max1+1<<' '<<max2+1<<endl;
	return 0;
}
