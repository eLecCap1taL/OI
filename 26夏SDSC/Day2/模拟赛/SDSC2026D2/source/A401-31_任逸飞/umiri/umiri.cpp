#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int n,m,a;
int lsad[max_n],cnt;
long long b;
long long d[max_n],ans;
priority_queue<int> st;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
long long read_(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		a=read(),b=read_();
		while(!st.empty()&&b>0){
			int r=st.top();
			st.pop();
			if(r<a){
				int flen=a-r;
				if(b>=flen*(-d[r+1])){
					b-=flen*(-d[r+1]);
					d[a+1]=d[r+1];
					d[r+1]=0;
				}
				else{
					if(b>=flen){
						d[r+1]+=b/flen,d[a+1]-=b/flen;
					}
					d[r+1]++,d[r+b%flen+1]--;
					st.push(r+b%flen);
					b=0;
				}	
			}
			else{
				lsad[++cnt]=r;
			}
		}
		for(int i=cnt;i>=1;i--){
			st.push(lsad[i]);
		}
		cnt=0;
		st.push(a);
		if(b>0){
			if(b>=a){
				d[1]+=b/a,d[a+1]-=b/a;
			}
			d[1]++,d[b%a+1]--;
			st.push(b%a);
			b=0;
		}
	}
	for(int i=1;i<=n;i++){
		ans+=d[i];
		printf("%lld\n",ans);
	}
	return 0;
}
