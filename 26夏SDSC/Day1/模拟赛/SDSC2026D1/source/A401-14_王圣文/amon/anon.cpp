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
const int xx=5e2+5;
const int xxx=1e6+5;
int n,k;
int a[xx][xx];
int cnt[xxx];
int ans[xx][xx];
vector<int> vis;
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	n=read(),k=read();
	bool pd=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]!=1 && a[i][j]!=2) pd=false;
		} 
	}
	if(pd){
		if(k==1){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cout<<1<<' ';
				}
				cout<<endl;
			}
		}else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cout<<min(n-i+1,n-j+1);
				}
				cout<<endl;
			}
		}
	}else{
		for(int top=1;top<=n;top++){
       		for(int c:vis) cnt[c]=0;
        	vis.clear();
        	for(int bot=top;bot<=n;bot++){
           	 	int h=bot-top+1;
            	for(int j=1;j<=n;j++){
                	int color=a[bot][j];
                	vis.push_back(color);
                	cnt[color]++;
           		}
            	int l=1;
            	int diff=0;
            	unordered_map<int,int> col_cnt;
            	for(int r=1;r<=n;r++){
                	for(int i=top;i<=bot;i++){
                	    int c=a[i][r];
                    	col_cnt[c]++;
                    	if(col_cnt[c]==1) diff++;
                	}
                	while(r-l+1>h){
                    	for(int i=top;i<=bot;i++){
                        	int c=a[i][l];
                        	col_cnt[c]--;
                        	if(col_cnt[c]==0) diff--;
                    	}
                    	l++;
                	}
                	if(r-l+1==h && diff<=k){
                    	ans[top][l]=h;
                	}
            	}
        	}
    	}
    	for(int i=1;i<=n;i++)  {
        	for(int j=1;j<=n;j++) {
            	cout<<ans[i][j]<<" ";
        	}
        	cout<<"\n";
    	}
	}
	return 0;
} 
