  #include<bits/stdc++.h>
  using namespace std;
  int t,n,k,m,b[2000005];
  int main(){
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>m;
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }   
        if((n-m)%(k-1)!=0){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag=false;
        for(int i=1;i<=m;i++){
            if(b[i]-i>=(k-1)/2&&n-m+i-b[i]>=(k-1)/2){
                cout<<"YES"<<endl;
                flag=true;
                break;
            }
        } 
        if(flag==false){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
