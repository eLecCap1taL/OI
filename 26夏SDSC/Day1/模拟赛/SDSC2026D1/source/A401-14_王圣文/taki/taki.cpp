#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
const int xx=3e3+3;
int k,q;
int a[xx],b[xx],c[xx];
int main(){
	freopen("taki.in","r",stdin);
	freopen("taki.out","w",stdout);
	k=read(),q=read();
	for(int i=1;i<=k;i++){
		int s=read();
		vector<int> q;
		for(int i=1;i<=s;i++){
			q.push_back(read());
		}
		long long ans=0;
		for(int i=1;i<=s;i++){
			for(int j=1;j<=i;j++){
				ans=ans+q[j-1]; 
			}
		}
		cout<<ans<<'\n'; 
	}
	return 0;
}
