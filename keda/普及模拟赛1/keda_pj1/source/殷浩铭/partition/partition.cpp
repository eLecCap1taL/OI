#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[25];
int p[32];
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=30;i++)p[i]=p[i-1]+p[i-1];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	long long ans=0;
	for(int i=0;i<p[n];i++){
		int A=0,B=0;
		for(int j=0;j<n;j++){
			int bit=(i/p[j])%2;
			int val=a[j];
			for(int k=0;k<=30;k++)
			{
				int bv=(val/p[k])%2;
				if(bv==0)continue;
				if(bit){
					int ba=(A/p[k])%2;
					if(ba==0)A=A+p[k];
				}
				else{
					int bb=(B/p[k])%2;
					if(bb==0)B=B+p[k];
				}
			}
		}
		if(A==B)ans++;
	}
	ans%=MOD;
	cout<<ans<<endl;
	return 0;
}
