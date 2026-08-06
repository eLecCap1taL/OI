#include<bits/stdc++.h>
using namespace std;
int T,n,k,m,a[2000009],t[2000009],p[2000009];
int main() {
	freopen("uika.in","r",stdin);
	freopen("uika.out","w",stdout);
	cin>>T;
	for(int oo=1; oo<=T; oo++) {
		cin>>n>>k>>m;
		for(int i=1; i<=m; i++) {
			cin>>a[i];
			t[a[i]]=1;
		}
		queue<int> q,q1;
		int ll=0,rr=0;
		for(int i=1; i<=n; i++) {
			if(!t[i]) {
				if(ll<k/2+1)
					q.push(i),ll++;
				else q1.push(i),rr++;
			}
			if(rr==k/2) {
				while(!q1.empty()) {
					t[q.front()]=2;
					t[q1.front()]=2;
					q.pop(),q1.pop();
				}
				rr=0,ll=1;
			}
		}
		k/=2;
		int l=1,r=n,l1=0,r1=0;
		for(int i=1; i<=n; i++)
			if(t[i]==1) p[i]=1+p[i-1];
			else p[i]=p[i-1];
		for(; l<r; l++) {
			if(!t[l]) l1++;
			if(l1%k==0) {
				while(r>l&&p[l]!=p[r]&&r1<l1) {
					if(!t[r]) r1++;
					r--;
				}
				int h=min(l1/k,r1/k);
				l1-=h*k,r1-=h*k;
			}
		}
		if(t[l]==1&&r1==0&&l1==0)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		for(int i=1; i<=n; i++)
			t[i]=0,p[i]=0;
	}
	return 0;
}

