#include<iostream>
using namespace std;
int main() {
    int n,x,y;
    int X1=1001,X2=-1,Y1=1001,Y2=-1;
    cin>>n;
    while(n--) {
        cin>>x>>y;
        if (x<X1){
        	X1=x;
		}
        if (x>X2){
        	X2=x;
		}
        if (y<Y1){
        	Y1=y;
		}
        if (y>Y2){
        	Y2=y;
		}
    }
    
    cout<<X1-1<<" "<<Y1-1<<endl;
    cout<<X2+1<<" "<<Y2+1;
    return 0;
}
