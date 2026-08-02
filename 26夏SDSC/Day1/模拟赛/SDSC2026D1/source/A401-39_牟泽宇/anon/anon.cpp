#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505;
ll n,K,a[N][N],ans[N][N];
int main(){
	freopen("anon.in","r",stdin);
	freopen("anon.out","w",stdout);
	cin>>n>>K;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(ll k=1;k<=n;k++){
		set<ll>st;
		multiset<ll>s;
		for(ll i=k,j=1,l=k,r=1;j<=n&&i<=n;){
			while(l<=n&&r<=n){
				for(ll q=i;q<=l;q++){
					s.insert(a[q][r]);
					st.insert(a[q][r]);
				}
				for(ll q=j;q<=r-1;q++){
					s.insert(a[l][q]);
					st.insert(a[l][q]);
				}
				if(st.size()>K){
					for(ll q=i;q<=l;q++){
						s.erase(s.find(a[q][r]));
						if(s.count(a[q][r])==0)st.erase(a[q][r]);
					}
					for(ll q=j;q<=r-1;q++){
						s.erase(s.find(a[l][q]));
						if(s.count(a[l][q])==0)st.erase(a[l][q]);
					}
					break;
				}
				l++,r++;
				//cout<<st.size()<<" "<<l<<" "<<r<<"\n";
			}
			ans[i][j]=l-i;
			//cout<<s.size()<<" "<<st.size()<<"\n";
			//cout<<"\n";
			for(ll q=i;q<l;q++){
				//cout<<q<<" "<<j<<" "<<a[q][j]<<"\n";
				s.erase(s.find(a[q][j]));
				if(s.count(a[q][j])==0)st.erase(a[q][j]);
			}
			for(ll q=j+1;q<r;q++){
				//cout<<i<<" "<<q<<" "<<a[i][q]<<"\n";
				s.erase(s.find(a[i][q]));
				if(s.count(a[i][q])==0)st.erase(a[i][q]);
			}
			i++,j++;
			//cout<<s.size()<<" "<<st.size()<<"\n";
		}
	}
	for(ll k=2;k<=n;k++){
		set<ll>st;
		multiset<ll>s;
		for(ll i=1,j=k,l=1,r=k;j<=n&&i<=n;){
			while(l<=n&&r<=n){
				for(ll q=i;q<=l;q++){
					s.insert(a[q][r]);
					st.insert(a[q][r]);
				}
				for(ll q=j;q<=r-1;q++){
					s.insert(a[l][q]);
					st.insert(a[l][q]);
				}
				if(st.size()>K){
					for(ll q=i;q<=l;q++){
						s.erase(s.find(a[q][r]));
						if(s.count(a[q][r])==0)st.erase(a[q][r]);
					}
					for(ll q=j;q<=r-1;q++){
						s.erase(s.find(a[l][q]));
						if(s.count(a[l][q])==0)st.erase(a[l][q]);
					}
					break;
				}
				l++,r++;
				//cout<<st.size()<<" "<<l<<" "<<r<<"\n";
			}
			ans[i][j]=l-i;
			//cout<<s.size()<<" "<<st.size()<<"\n";
			//cout<<"\n";
			for(ll q=i;q<l;q++){
				//cout<<q<<" "<<j<<" "<<a[q][j]<<"\n";
				s.erase(s.find(a[q][j]));
				if(s.count(a[q][j])==0)st.erase(a[q][j]);
			}
			for(ll q=j+1;q<r;q++){
				//cout<<i<<" "<<q<<" "<<a[i][q]<<"\n";
				s.erase(s.find(a[i][q]));
				if(s.count(a[i][q])==0)st.erase(a[i][q]);
			}
			i++,j++;
			//cout<<s.size()<<" "<<st.size()<<"\n";
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
/*

5 4
1 2 3 3 2
4 5 1 3 1
2 3 5 5 5
5 3 1 2 3
3 3 3 1 2

6 5
3 3 5 1 2 3
1 5 6 3 1 4
1 3 6 2 3 5
3 5 6 5 3 6
5 3 6 5 5 2
3 2 6 3 2 1
*/

/*

for(ll l=1,r=1;l<=r;){
	while(l<=n&&r<=n){
		sum+=a[r];
		if(sum>k){
			sum-=a[r];
			break;
		}
		r++;
	}
	ans++;
	sum-=a[l];
	l++
}

*/
